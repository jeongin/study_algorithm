#include <iostream>
#include <algorithm>

using namespace std;

int N;
int triangle[401][801];
int ans;
int dp[401][801];

void cal() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y <= 2 * x; y++) {
			for (int size = 2; size <= N; size++) {
				if (x + size - 1 > N - 1) continue;

				if (y % 2 == 0) {
					if (y + 2 * (size - 1) > 2 * (x + size - 1)) continue;

					for (int k = 0; k <= 2 * (size - 1); k++) {
						dp[x][y] += triangle[x + size - 1][y + k];
					}
				}
				else {
					if ((y + 2 * (size - 1)) > (2 * x + 1)) continue;

					for (int k = 0; k < size - 1; k++) {
						for (int p = 1; p < 3; p++) {
							dp[x][y] += triangle[x + k][y + 2 * k + p];
						}
					}
					dp[x][y] += triangle[x + size - 1][y + 2 * (size - 1)];
				}
				if (ans < dp[x][y]) ans = dp[x][y];
			}
		}
	}

}

int main() {
	// baekjoon 4902

	int cnt = 0;
	while (1) {
		ans = 0;
		cnt++;
		scanf("%d", &N);

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= 2 * i; j++) {
				scanf("%d", &triangle[i][j]);
				dp[i][j] = triangle[i][j];
				if (ans < dp[i][j]) ans = dp[i][j];
			}
		}

		cal();

		printf("%d. %d\n", cnt, ans);
	}

	getchar();
	getchar();

	return 0;
}