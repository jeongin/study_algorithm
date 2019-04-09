#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S[20][20];
vector<int> team[2];
int ans = 0x7fffffff;

void dfs(int idx) {
	if (team[0].size() == N / 2 && team[1].size() == N / 2) {
		int t1 = 0, t2 = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;
				t1 += S[team[0][i]][team[0][j]];
				t2 += S[team[1][i]][team[1][j]];
			}
		}

		int diff = (t1 > t2) ? t1 - t2 : t2 - t1;
		if (ans > diff) ans = diff;

		return;
	}

	if (team[0].size() < N / 2) {
		team[0].push_back(idx);
		dfs(idx + 1);
		team[0].pop_back();
	}

	if (team[1].size() < N / 2) {
		team[1].push_back(idx);
		dfs(idx + 1);
		team[1].pop_back();
	}
}

int main() {
	// baekjoon 14889

	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> S[x][y];
		}
	}

	dfs(0);

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}