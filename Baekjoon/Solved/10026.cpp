#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct xy {
	int x, y;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N;
char board[100][100][2];
int check[100][100];
int ans[2];
queue<xy> q;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = 0;
		}
	}
}

void bfs(char color, int type) {
	while (!q.empty()) {
		xy now = q.front(); q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (board[nx][ny][type] == color && check[nx][ny] == 0) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
	ans[type]++;
}

int main() {
	// baekjoon 10026

	scanf("%d", &N);
	char tmp[100];
	for (int i = 0; i < N; i++) {
		scanf("%s", tmp);
		for (int j = 0; j < N; j++) {
			board[i][j][0] = tmp[j];
			board[i][j][1] = tmp[j];
			if (tmp[j] == 'G')
				board[i][j][1] = 'R';
		}
	}

	char color;
	for (int n = 0; n < 2; n++) {
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == 0) {
					check[i][j] = 1;
					color = board[i][j][n];
					q.push({ i,j });
					bfs(color, n);
				}
			}
		}
	}

	/*
	for (int i = 0; i < N; i++) {
	for (int j = 0; j < N; j++) {
	printf("%c ", board[i][j]);
	}
	printf("\n");
	}
	*/

	printf("%d %d\n", ans[0], ans[1]);

	getchar();
	getchar();

	return 0;
}