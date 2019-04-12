#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct info {
	int x, y, time;
};

struct open {
	bool door[4]; //µ¿ ³² ¼­ ºÏ
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool tunnel[8][4] = { { 0, 0, 0, 0 },{ 1, 1, 1, 1 },{ 0, 1, 0, 1 },{ 1, 0, 1, 0 },
{ 1, 0, 0, 1 },{ 1, 1, 0 , 0 },{ 0, 1, 1, 0 },{ 0, 0, 1, 1 } };
int H, W, R, C, L;
int board[50][50];
open O[50][50];

int main(int argc, char** argv) {
	// samsung 1953

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> H >> W >> R >> C >> L;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				cin >> board[x][y];

				for (int k = 0; k < 4; k++) {
					O[x][y].door[k] = tunnel[board[x][y]][k];
				}
			}
		}


		int x, y, time;
		int nx, ny;
		int check[50][50] = { 0, };

		queue<info> q;
		q.push({ R, C, 1 });
		check[q.front().x][q.front().y] = 1;
		while (!q.empty()) {
			x = q.front().x, y = q.front().y, time = q.front().time;
			q.pop();

			if (time == L) continue;

			for (int i = 0; i < 4; i++) {
				nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < H && ny >= 0 && ny < W && check[nx][ny] == 0
					&& O[x][y].door[i] == 1 && O[nx][ny].door[(i + 2) % 4] == 1) {
					check[nx][ny] = 1;
					q.push({ nx, ny, time + 1 });
				}
			}
		}

		int cnt = 0;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				if (check[x][y] == 1) cnt++;
			}
		}

		cout << "#" << t << " " << cnt << endl;
	}


	getchar();
	getchar();

	return 0;
}