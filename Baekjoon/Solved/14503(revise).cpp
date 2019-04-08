#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct piii {
	int x, y, dir;
};

// ºÏ µ¿ ³² ¼­
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int H, W;
int board[50][50];
queue<piii> q;
int ans;

int main() {
	// baekjoon 14503

	cin >> H >> W;

	int sx, sy, sd;
	cin >> sx >> sy >> sd;

	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> board[x][y];
		}
	}

	q.push({ sx, sy, sd });
	board[sx][sy] = 2;
	ans++;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().dir;
		q.pop();

		int nx, ny, ndir;
		int check = 0;
		for (int i = 3; i >= 0; i--) {
			ndir = (d + i) % 4;
			nx = x + dx[ndir];
			ny = y + dy[ndir];

			if (nx >= 1 && nx < H - 1 && ny >= 1 && ny < W - 1 && board[nx][ny] == 0) {
				board[nx][ny] = 2;
				ans++;
				q.push({ nx, ny, ndir });
				check = 1;
				break;
			}
		}

		if (check == 0) {
			ndir = (d + 2) % 4;
			nx = x + dx[ndir];
			ny = y + dy[ndir];
			if (board[nx][ny] != 1) q.push({ nx,ny,d });
		}
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}