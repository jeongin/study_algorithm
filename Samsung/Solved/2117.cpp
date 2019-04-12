#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int N, M;
int board[20][20];
int max_home;
int ans;

int pay(int k) {
	return (2 * k * k - 2 * k + 1);
}

void solve(int cur_x, int cur_y) {
	int k = 1;
	int max_k = max(cur_x + cur_y, max(2 * N - cur_x - cur_y, max(N - cur_x + cur_y, N - cur_y + cur_x)));

	while (k <= max_k) {
		int secure[20][20] = { 0, };
		int cnt = 0;
		for (int x = cur_x - k + 1; x < cur_x + k; x++) {
			for (int y = cur_y - k + 1; y < cur_y + k; y++) {
				if (x >= 0 && x < N && y >= 0 && y < N && (abs(cur_x - x) + abs(cur_y - y)) < k) {
					secure[x][y] = 1;
					if (board[x][y] == 1) {
						cnt++;
					}
				}
			}
		}

		int cal = cnt * M - pay(k);
		if (cal >= 0 && ans < cnt) {
			ans = cnt;
		}
		k++;
	}
}

int main(int argc, char** argv) {
	// samsung 2117

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		ans = 0x7fffffff + 1;

		cin >> N >> M;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> board[x][y];
			}
		}

		max_home = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				solve(x, y);
			}
		}
		cout << "#" << t << " " << ans << endl;
	}

	getchar();
	getchar();

	return 0;
}