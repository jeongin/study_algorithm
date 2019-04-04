#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };
int dc[2] = { 1, -1 };

int R, C;
int N;
char board[101][101];
int check[101][101];

void print_board() {
	for (int i = R; i >= 1; i--) {
		//printf("[%2d] ", i);
		for (int j = 1; j <= C; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int del_m(int x, int turn) {
	int c;
	if (turn == 0) c = 1;
	else c = C;

	while (c >= 1 && c <= C) {
		if (board[x][c] == 'x') {
			board[x][c] = '.';
			return c;
		}
		c += dc[turn];
	}

	return 0;
}

void check_cluster(int x, int y) {
	if (x < 1 || x > R || y < 1 || y > C) return;

	if (board[x][y] == '.') return;

	if (check[x][y]) return;
	check[x][y] = 1;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (board[nx][ny] == 'x')
			check_cluster(nx, ny);
	}
}

int get_height() {
	int ret = R + 1;
	for (int i = 1; i <= C; i++) {
		int cnt = R + 1;
		int x1 = R + 1, x2 = 0;
		for (int j = R; j >= 1; j--) {
			if (board[j][i] == 'x' && check[j][i] == 1)
				x1 = j;
			if (x1 != R + 1 && x2 == 0 && board[j][i] == 'x' && check[j][i] == 0) {
				x2 = j;
				break;
			}
		}
		if (x1 != R + 1 && x2 != 0) cnt = x1 - x2 - 1;
		if (x1 == 1) return 0;
		ret = min(ret, cnt);
	}

	return ret;
}

void down(int h) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (check[i][j] == 1 && board[i][j] == 'x') {
				board[i - h][j] = 'x';
				board[i][j] = '.';
			}
		}
	}
}

int main() {
	// baekjoon 2933

	scanf("%d %d", &R, &C);

	string input;
	for (int i = R; i >= 1; i--) {
		cin >> input;
		for (int j = 1; j <= C; j++) {
			board[i][j] = input[j - 1];
		}
	}

	scanf("%d", &N);
	queue<int> wing;
	int tmp;
	/*for (int i = 0; i < N; i++) {
	scanf("%d", &tmp);
	wing.push(tmp);
	}*/

	/*
	1. 미네랄 지우기
	2. 공중에 떠있는 클러스터 체크
	3. 공중에 떠있는 높이 구하기
	4. 공중에 떠있는 클러스터 내리기
	*/

	int turn = 0;
	int x, y;
	while (N) {
		scanf("%d", &tmp);
		wing.push(tmp);
		N--;
		x = wing.front(); wing.pop();

		/*printf("============================\n");
		printf("--------------------------------\n");
		printf("[turn]: %d [x]: %d\n", turn, x);
		printf("--------------------------------\n");*/

		y = del_m(x, turn);
		if (y != 0) {
			int nx, ny;
			for (int i = 0; i < 4; i++) {
				memset(check, 0, sizeof(check));
				nx = x + dx[i];
				ny = y + dy[i];
				check_cluster(nx, ny);

				int h = get_height();

				if (h == R + 1 || h == 0) continue;

				down(h);
			}
		}
		int nx, ny;
		for (int i = 0; i < 4; i++) {
			memset(check, 0, sizeof(check));
			nx = x + dx[i];
			ny = y + dy[i];
			check_cluster(nx, ny);

			int h = get_height();

			if (h == R + 1 || h == 0) continue;

			down(h);
		}

		//print_board();
		turn = !turn;
	}

	print_board();

	getchar();
	getchar();

	return 0;
}