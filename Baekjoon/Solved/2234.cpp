#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct xy {
	int x, y;
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };

int H, W;
int board[50][50][5];
int cnt_room;
int room_size;
int max_size;
int check[50][50];
int del_check[50][50][4];
queue<xy> q;

void bfs(int type) {
	int size = 1;
	while (!q.empty()) {
		xy now = q.front(); q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = now.x + dx[i];
			ny = now.y + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

			if (check[nx][ny] == 0 && board[now.x][now.y][i] == 0) {
				board[nx][ny][4] = cnt_room;
				check[nx][ny] = 1;
				size++;
				q.push({ nx,ny });
			}
		}
	}

	if (type == 0) {
		cnt_room++;
		if (room_size < size) room_size = size;
	}
	if (max_size < size) max_size = size;
}

void room(int type) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			check[i][j] = 0;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (check[i][j] == 0) {
				if (type == 0) board[i][j][4] = cnt_room;
				check[i][j] = 1;
				q.push({ i,j });
				bfs(type);
			}
		}
	}
}

void del_wall() {
	int nx, ny;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			for (int k = 0; k < 4; k++) {
				if (board[x][y][k] == 1 && del_check[x][y][k] == 0) {
					nx = x + dx[k];
					ny = y + dy[k];

					if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

					del_check[x][y][k] = 1;
					del_check[nx][ny][(k + 2) % 4] = 1;
					board[x][y][k] = 0;
					board[nx][ny][(k + 2) % 4] = 0;
					room(1);
					board[x][y][k] = 1;
					board[nx][ny][(k + 2) % 4] = 1;
				}
			}
		}
	}
}

int main() {
	// baekjoon 2234

	scanf("%d %d", &W, &H);
	int tmp;
	for (int i = 0; i < H; i++) {
		int down = 0, right = 0, top = 0, left = 0;
		for (int j = 0; j < W; j++) {
			scanf("%d", &tmp);

			if (tmp / 8) board[i][j][0] = 1;
			tmp %= 8;
			if (tmp / 4) board[i][j][1] = 1;
			tmp %= 4;
			if (tmp / 2) board[i][j][2] = 1;
			tmp %= 2;
			if (tmp) board[i][j][3] = 1;
		}
	}

	room(0);
	del_wall();

	printf("%d\n%d\n%d\n", cnt_room, room_size, max_size);

	getchar();
	getchar();

	return 0;
}