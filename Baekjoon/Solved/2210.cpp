#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };

int board[5][5];
int num[1000000];

void jump(int n, int x, int y, long long now) {
	if (n == 5) {
		num[now] = 1;
		return;
	}

	int nx, ny;
	long long nn;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		nn = 10 * now + board[nx][ny];
		jump(n + 1, nx, ny, nn);
	}
}

int main() {
	// baekjoon 2210

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			jump(0, i, j, board[i][j]);
		}
	}

	int ans = 0;
	for (long long i = 0; i < 1000000; i++) {
		if (num[i] == 1) {
			ans++;
		}
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}