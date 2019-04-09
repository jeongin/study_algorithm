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
	check[x][y] = 1;

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (board[nx][ny] == 'x' && check[nx][ny] == 0) check_cluster(nx, ny);
	}
}

int get_height() {
	int ret = R + 1;
	for (int y = 1; y <= C; y++) {
		int cnt = 0;
		for (int x = 1; x <= R; x++) {
			if (board[x][y] == 'x' && check[x][y] == 1) cnt = 0;
			else if (board[x][y] == '.') cnt++;
			else if (board[x][y] == 'x' && check[x][y] == 0) {
				ret = min(ret, cnt);
				break;
			}
		}
	}

	return ret;
}

void down(int h) {
	for (int y = 0; y <= C; y++) {
		for (int x = 0; x <= R; x++) {
			if (check[x][y] == 0 && board[x][y] == 'x') {
				board[x - h][y] = 'x';
				board[x][y] = '.';
			}
		}
	}
}

int main() {
	// baekjoon 2933

	scanf("%d %d", &R, &C);

	string input;
	for (int i = R; i >= 0; i--) {
		if (i != 0) cin >> input;

		for (int j = 1; j <= C; j++) {
			if (i == 0) board[i][j] = 'x';
			else board[i][j] = input[j - 1];
		}
	}

	scanf("%d", &N);
	queue<int> wing;
	int tmp;

	/*
	1. 미네랄 지우기
	2. 공중에 떠있는 클러스터 체크
	3. 공중에 떠있는 높이 구하기
	4. 공중에 떠있는 클러스터 내리기
	*/

	int turn = 0;
	int x, y;
	while (N) {
		N--;

		scanf("%d", &tmp);
		wing.push(tmp);
		x = wing.front(); wing.pop();
		y = del_m(x, turn);

		if (y != 0) {
			memset(check, 0, sizeof(check));
			check_cluster(0, 1);
			int h = get_height();
			if (h < R + 1) down(h);
		}

		turn = !turn;
	}

	print_board();

	getchar();
	getchar();

	return 0;
}