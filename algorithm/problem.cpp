#include <iostream>
#include <algorithm>

using namespace std;

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 }; 
int board[10][10];
int paper[5] = { 5, 5, 5, 5, 5 };
int ans = 100000;

int find_size(int x, int y) {
	int size = 0;
	int nx, ny;
	/*printf("=========================\n");
	printf("[x]: %d [y]: %d\n", x, y);*/
	for (int n = 0; n < 10; n++) {
		if (x + n >= 10 || y + n >= 10) return size;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (board[x + i][y + j] == 0) return size;
			}
		}
		size++;

		if (size == 5) return size;
	}

	return size;
}

void dfs(int x, int y, int cnt)
{
	if (cnt >= ans - 1) return;

	int size = find_size(x, y);
	for (int n = size-1; n >= 0; n--) { // 크기 1부터 size 까지
		if (paper[n] == 0) continue;

		if (x + size - 1 >= 10 || y + size - 1 >= 10) continue;

		paper[n]--;
		for (int nx = 0; nx <= n; nx++) { // 1으로 설정
			for (int ny = 0; ny <= n; ny++) {
				board[x + nx][y + ny] = 0;
			}
		}

	/*	printf("================================\n");
		printf("[x]: %d [y]: %d [cnt]: %d\n", x, y, cnt);
		for (int nx = 0; nx < 10; nx++) {
			for (int ny = 0; ny < 10; ny++) {
				printf("%d ", board[nx][ny]);
			}
			printf("\n");
		}*/

		int check = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] == 1) {
					check = 1;
					break;
				}
			}
			if (check == 1) break;
		}

		if (check == 0) {
			if (ans > cnt) ans = cnt + 1;
			paper[n]++;
			for (int nx = 0; nx <= n; nx++) { // 1으로 설정
				for (int ny = 0; ny <= n; ny++) {
					board[x + nx][y + ny] = 1;
				}
			}
			return;
		}

		for (int nx = 0; nx < 10; nx++) {
			for (int ny = 0; ny < 10; ny++) {
				if (board[nx][ny] == 1) dfs(nx, ny, cnt + 1);
			}
		}

		paper[n]++;
		for (int nx = 0; nx <= n; nx++) { // 1으로 설정
			for (int ny = 0; ny <= n; ny++) {
				board[x + nx][y + ny] = 1;
			}
		}
	}

	
}

int main() {
	// baekjoon 17136

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			scanf("%d", &board[x][y]);
		}
	}
	
	int check = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) {
				check = 1;
				break;
			}
		}
		if (check == 1) break;
	}

	if (check == 0) {
		ans = 0;
	}

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if(board[x][y] == 1) dfs(x, y, 0);
		}
	}
	
	printf("[ans]: %d\n", ans);

	getchar();
	getchar();

	return 0;
}