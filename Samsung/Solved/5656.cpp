#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct piii {
	int x, y, len;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, W, H;
int board[15][12];
queue <piii> q;
int ans = 0x7fffffff;

void copy_board(int a[15][12], int b[15][12]) {
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			b[x][y] = a[x][y];
		}
	}
}

void drop(int n, int column) {
	if (n == N) {
		int cnt = 0;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				if (board[x][y] > 0) cnt++;
			}
		}

		if (ans > cnt) ans = cnt;

		return;
	}

	int check[15][12];
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			check[x][y] = 0;
		}
	}

	for (int x = 0; x < H; x++) {
		if (board[x][column] > 0) {
			q.push({ x, column, board[x][column] });
			check[x][column] = 1;
			board[x][column] = 0;
			break;
		}
	}

	if (n == 0 && column == 2) {
		int aaa = 0;
	}

	if (n == 1 && column == 2) {
		int aaa = 0;
	}

	if (n == 2 && column == 6) {
		int aaa = 0;
	}

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, len = q.front().len; q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < len; j++) {
				nx = x + dx[i] * j, ny = y + dy[i] * j;
				if (nx >= 0 && nx < H && ny >= 0 && ny < W && board[nx][ny] > 0 && check[nx][ny] == 0) {
					check[nx][ny] = 1;
					q.push({ nx,ny,board[nx][ny] });
					board[nx][ny] = 0;
				}
			}
		}
	}

	for (int y = 0; y < W; y++) {
		int idx = H - 1;
		for (int x = H - 1; x >= 0; x--) {
			if (board[x][y] > 0) {
				board[idx][y] = board[x][y];
				if (x != idx) board[x][y] = 0;
				idx--;
			}
		}
	}

	/*printf("[%dth]: %d=================\n", n, column);
	for (int x = 0; x < H; x++) {
	for (int y = 0; y < W; y++) {
	cout << board[x][y] << " ";
	}
	cout << endl;
	}*/

	int tmp[15][12];
	copy_board(board, tmp);
	for (int y = 0; y < W; y++) {
		drop(n + 1, y);
		copy_board(tmp, board);
	}

}

int main(int argc, char** argv) {
	// samsung 5656

	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		ans = 0x7fffffff;
		cin >> N >> W >> H;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				cin >> board[x][y];
			}
		}
		int tmp[15][12];
		copy_board(board, tmp);
		for (int y = 0; y < W; y++) {
			drop(0, y);
			copy_board(tmp, board);
		}

		cout << "#" << test_case << " " << ans << "\n";
	}

	getchar();
	getchar();

	return 0;
}