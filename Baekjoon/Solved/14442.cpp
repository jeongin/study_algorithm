#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct node {
	int x, y, broken;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, M, K;
int board[1000][1000];
int check[1000][1000][11];
int ans = -1;
queue<node> q;

int bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int k = q.front().broken;
		q.pop();

		if (x == N - 1 && y == M - 1) return check[x][y][k];

		int nx, ny, nk;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			nk = k + 1;
			if (board[nx][ny] == 0 && check[nx][ny][k] == 0) {
				check[nx][ny][k] = check[x][y][k] + 1;
				q.push({ nx, ny, k }); continue;
			}
			else if (board[nx][ny] == 1 && nk <= K) {
				if (check[nx][ny][nk] == 0) {
					check[nx][ny][nk] = check[x][y][k] + 1;
					q.push({ nx,ny, nk }); continue;
				}
			}
		}
	}

	return -1;
}

int main() {
	// baekjoon 14442

	scanf("%d %d %d", &N, &M, &K);
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '0')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}

	check[0][0][0] = 1;
	q.push({ 0,0, 0 });
	ans = bfs();

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}