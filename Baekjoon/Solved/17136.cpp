#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
int board[10][10];
vector<pair<int, int>> v;
int check[10][10];
int paper[5] = { 5, 5, 5, 5, 5 };
int ans = 100000;

int find_size(int x, int y) {
	int size = 0;
	int nx, ny;
	for (int n = 0; n < 5; n++) {
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

void dfs(int idx, int cnt) {
	/*printf("[idx]: %d [cnt]: %d===============\n", idx, cnt);
	for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 10; j++) {
	printf("%d ", check[i][j]);
	}
	printf("\n");
	}*/

	if (cnt >= ans) return;

	if (idx == v.size()) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] != check[i][j]) return;
			}
		}

		ans = cnt;
		return;
	}

	int x = v[idx].first;
	int y = v[idx].second;

	if (check[x][y] == 1) dfs(idx + 1, cnt);

	int size = find_size(x, y); // (x,y)에 붙일 수 있는 종이 크기 구하기
	for (int n = size - 1; n >= 0; n--) { // 크기 1부터 size 까지
		if (x + n >= 10 || y + n >= 10) continue;
		if (paper[n] == 0) continue;

		int end = 0;
		for (int nx = 0; nx <= n; nx++) { // 1으로 설정
			for (int ny = 0; ny <= n; ny++) {
				if (check[x + nx][y + ny] == 1) end = 1;
			}
		}
		if (end == 1) continue;

		paper[n]--;
		for (int nx = 0; nx <= n; nx++) { // 1으로 설정
			for (int ny = 0; ny <= n; ny++) {
				check[x + nx][y + ny] = 1;
			}
		}

		dfs(idx + 1, cnt + 1);

		paper[n]++;
		for (int nx = 0; nx <= n; nx++) { // 0으로 설정
			for (int ny = 0; ny <= n; ny++) {
				check[x + nx][y + ny] = 0;
			}
		}
	}
}

int main() {
	// baekjoon 17136

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			scanf("%d", &board[x][y]);
			if (board[x][y] == 1) v.push_back(make_pair(x, y));
		}
	}

	dfs(0, 0);

	if (ans != 100000) printf("%d\n", ans);
	else printf("-1\n");

	getchar();
	getchar();

	return 0;
}