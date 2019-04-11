#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };

int N, M, K;
deque<int> tree[10][10];
int ground[10][10];
int add[10][10];

void spring_summer() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int T = tree[x][y].size();
			int t;
			for (t = 0; t < T; t++) {
				if (tree[x][y][t] <= ground[x][y]) {
					ground[x][y] -= tree[x][y][t];
					tree[x][y][t] += 1;
				}
				else break;
			}

			for (t; t < T; t++) {
				ground[x][y] += tree[x][y].back() / 2;
				tree[x][y].pop_back();
			}

		}
	}
}

void fall() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int T = tree[x][y].size();
			for (int t = 0; t < T; t++) {
				if (tree[x][y][t] % 5 != 0) continue;

				int nx, ny;
				for (int i = 0; i < 8; i++) {
					nx = x + dx[i], ny = y + dy[i];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						tree[nx][ny].push_front(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			ground[x][y] += add[x][y];
		}
	}
}

int main() {
	// baekjoon 16235

	cin >> N >> M >> K;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> add[x][y];
			ground[x][y] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	while (K-- > 0) {
		spring_summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			ans += tree[x][y].size();
		}
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}