#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct monkey {
	int x, y, k;
};

int dx[12] = { -1, -2, -2, -1, 1, 2, 2, 1, 0, 1, 0, -1 };
int dy[12] = { -2, -1, 1, 2, -2, -1, 1, 2, 1, 0, -1, 0 };

int K, W, H;
int board[200][200];
int cnt[200][200][31];
queue<monkey> q;
int ans = -1;

int main() {
	// baekjoon  1600

	scanf("%d %d %d", &K, &W, &H);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	q.push({ 0,0,0 });
	while (!q.empty()) {
		auto m = q.front(); q.pop();

		if (m.x == H - 1 && m.y == W - 1)
		{
			ans = cnt[m.x][m.y][m.k];
			break;
		}

		int nx, ny, nk;
		for (int i = 0; i < 12; i++) {
			nx = m.x + dx[i];
			ny = m.y + dy[i];
			nk = m.k + 1;

			if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1) continue;

			if (board[nx][ny] == 0) {
				if (i < 8 && nk <= K && (cnt[nx][ny][nk] == 0 || cnt[nx][ny][nk] > cnt[m.x][m.y][m.k] + 1)) {
					cnt[nx][ny][nk] = cnt[m.x][m.y][m.k] + 1;
					q.push({ nx,ny,nk });
				}
				else if (i >= 8 && (cnt[nx][ny][m.k] == 0 || cnt[nx][ny][m.k] > cnt[m.x][m.y][m.k] + 1)) {
					cnt[nx][ny][m.k] = cnt[m.x][m.y][m.k] + 1;
					q.push({ nx,ny,m.k });
				}
			}
		}


		board[m.x][m.y] = 0;
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}