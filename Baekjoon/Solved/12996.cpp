#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 1000000007

using namespace std;

int S, D, K, H;
long long dp[51][51][51][51];

long long solve(int s, int d, int k, int h) {
	if (s == 0) {
		if (d == 0 && k == 0 && h == 0) return 1;
		else return 0;
	}

	if (d < 0 || k < 0 || h < 0)
		return 0;

	if (dp[s][d][k][h] != -1) return dp[s][d][k][h];

	long long ans = 0;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			for (int o = 0; o <= 1; o++) {
				if (i + j + o > 0) {
					ans = (ans + solve(s - 1, d - i, k - j, h - o)) % MOD;
				}
			}
		}
	}
	dp[s][d][k][h] = ans;
	return dp[s][d][k][h];
}

int main() {
	// baekjoon 12996

	scanf("%d %d %d %d", &S, &D, &K, &H);
	memset(dp, -1, sizeof(dp));

	printf("%lld\n", solve(S, D, K, H));

	getchar();
	getchar();

	return 0;
}