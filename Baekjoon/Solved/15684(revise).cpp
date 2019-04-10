#include <iostream>
#include <algorithm>

using namespace std;

int W, M, H;
int ladder[31][11];
int visit[31][11];

bool check_ladder() {
	for (int y = 1; y <= W; y++) {
		int site = y;
		for (int x = 1; x <= H; x++) {
			if (site > 1 && ladder[x][site - 1] == 1) site -= 1;
			else if (site < W && ladder[x][site] == 1) site += 1;
		}
		if (site != y) return false;
	}

	return true;
}

bool dfs(int cnt, int cur_x, int cur_y) {
	if (cnt == 0) {
		return check_ladder();
	}

	for (int x = cur_x; x <= H; x++) {
		for (int y = cur_y; y < W; y++) {
			if (ladder[x][y] == 1) continue;

			visit[x][y] = 1;
			ladder[x][y] = 1;
			if (dfs(cnt - 1, x, y + 2)) return true;
			ladder[x][y] = 0;
			visit[x][y] = 0;
		}
		cur_y = 1;
	}

	return false;
}

int main() {
	// baekjoon 15684

	cin >> W >> M >> H;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		ladder[x][y] = 1;
	}

	int n = 0;
	while (n <= 3) {
		if (dfs(n, 1, 1) == true) break;
		n++;
	}

	if (n > 3) cout << -1 << endl;
	else cout << n << endl;

	getchar();
	getchar();

	return 0;
}