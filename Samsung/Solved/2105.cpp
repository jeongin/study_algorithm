#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct info {
	int x, y, dir, cnt;
};

int dx[4] = { 1, 1, -1 ,-1 };
int dy[4] = { -1, 1, 1, -1 };

int N;
int board[20][20];
int dessert[101];
int check_x, check_y, check_dir;
int ans;

int dfs(int cur_x, int cur_y, int cur_dir, int turn, int cnt) {
	//cout << "[x]: " << cur_x << " [y]: " << cur_y << " [dir]: " << cur_dir << " [turn]: " << turn << " [cnt]: " << cnt << endl;
	if (cur_x == check_x && cur_y == check_y && turn == 4) {
		if (ans < cnt) ans = cnt;
		if (ans == 10) {
			int aaa = 0;
		}
		return 1;
	}


	int nx, ny;
	int ret = -1;

	nx = cur_x + dx[cur_dir], ny = cur_y + dy[cur_dir];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N && dessert[board[nx][ny]] == 0)
	{
		dessert[board[nx][ny]] = 1;
		ret = dfs(nx, ny, cur_dir, turn, cnt + 1);
		dessert[board[nx][ny]] = 0;
	}
	if (ret != -1) return ret;

	if (turn == 4) return -1;

	nx = cur_x + dx[(cur_dir + 1) % 4], ny = cur_y + dy[(cur_dir + 1) % 4];
	if (nx >= 0 && nx < N && ny >= 0 && ny < N && dessert[board[nx][ny]] == 0)
	{
		dessert[board[nx][ny]] = 1;
		ret = dfs(nx, ny, (cur_dir + 1) % 4, turn + 1, cnt + 1);
		dessert[board[nx][ny]] = 0;
	}
	if (ret != -1) return ret;

	return -1;
}

int main(int argc, char** argv) {
	// samsung 2105 14:00 ½ÃÀÛ

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		ans = -1;

		cin >> N;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> board[x][y];
			}
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (x == 0 && y == 0) continue;
				if (x == 0 && y == N - 1) continue;
				if (x == N - 1 && y == 0) continue;
				if (x == N - 1 && y == N - 1) continue;

				check_x = x, check_y = y;
				for (int i = 0; i < 4; i++) {
					check_dir = i;
					for (int a = 0; a < N; a++) {
						for (int b = 0; b < N; b++) {
							dessert[board[a][b]] = 0;
						}
					}
					dfs(x, y, i, 0, 0);
				}
			}
		}

		cout << "#" << t << " " << ans << endl;
	}

	getchar();
	getchar();

	return 0;
}