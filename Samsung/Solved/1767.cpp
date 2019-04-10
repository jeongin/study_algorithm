#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int T, N;
int board[12][12];
vector<pair<int, int>> core;
int max_connect;
int line;

void dfs(int idx, int connect, int cost) {
	if (idx == core.size()) {
		if (connect > max_connect) {
			max_connect = connect;
			line = cost;
		}
		else if (connect == max_connect && cost < line) line = cost;

		return;
	}

	int x = core[idx].first, y = core[idx].second;
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
		dfs(idx + 1, connect + 1, cost);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x, ny = y;
		bool check = true;
		int len = 0;
		while (1) {
			nx += dx[i], ny += dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
			if (board[nx][ny] > 0) {
				check = false;
				break;
			}

			board[nx][ny] = 2;
			len++;
		}
		if (check) dfs(idx + 1, connect + 1, cost + len);
		while (nx - dx[i] != x || ny - dy[i] != y) {
			nx -= dx[i], ny -= dy[i];
			board[nx][ny] = 0;
		}
	}

	dfs(idx + 1, connect, cost);

}

int main() {
	// samsung 1767

	//freopen("sample_input.txt", "r", stdin);

	cin >> T;

	while (T-- > 0) {
		line = 0x7ffffff;
		max_connect = 0;
		core.clear();

		cin >> N;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> board[x][y];
				if (board[x][y] == 1) core.push_back({ x,y });
			}
		}

		dfs(0, 0, 0);

		cout << "#" << n++ << " " << line << endl;
	}

	return 0;
}