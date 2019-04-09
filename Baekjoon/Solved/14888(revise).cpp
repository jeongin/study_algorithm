#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[11];
int op[4]; // + - x /
long long ans[2]; // max min

void dfs(long long now, int cnt) {
	if (cnt == N - 1) {
		if (ans[0] < now) ans[0] = now;
		if (ans[1] > now) ans[1] = now;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;

			int tmp = now;
			if (i == 0) {
				tmp += num[cnt + 1];
			}
			else if (i == 1) {
				tmp -= num[cnt + 1];
			}
			else if (i == 2) {
				tmp *= num[cnt + 1];
			}
			else if (i == 3) {
				tmp /= num[cnt + 1];
			}
			dfs(tmp, cnt + 1);

			op[i]++;
		}
	}

}

int main() {
	// baekjoon 14888

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> num[n];
	}

	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	ans[0] = 0x7fffffff + 1;
	ans[1] = 0x7fffffff;
	dfs(num[0], 0);

	cout << ans[0] << endl << ans[1] << endl;

	getchar();
	getchar();

	return 0;
}