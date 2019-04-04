#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int N, M, P;
long long dp[101][101];

int main() {
	// baekjoon 12872

	scanf("%d %d %d", &N, &M, &P);

	dp[0][0] = 1;

	long long tmp;
	for (int i = 1; i <= P; i++) {
		for (int j = 0; j <= N; j++) {
			tmp = dp[i][j];
			if (j > 0) {
				tmp += dp[i - 1][j - 1] * (N - j + 1);
				tmp %= MOD;
			}
			if (j > M) {
				tmp += dp[i - 1][j] * (j - M);
				tmp %= MOD;
			}
			dp[i][j] = tmp;
		}
	}

	printf("%lld\n", dp[P][N]);

	getchar();
	getchar();

	return 0;
}