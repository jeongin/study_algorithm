#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
char S[30];
bool dp[30][30][30][450];

bool solve(int cur, int a, int b, int p)
{
	if (p == K && cur == N)
		return true;
	else if (p != K && cur == N)
		return false;

	if (dp[cur][a][b][p])
		return false;
	dp[cur][a][b][p] = true;

	S[cur] = 'A';
	if (solve(cur + 1, a + 1, b, p)) return true;
	S[cur] = 'B';
	if (solve(cur + 1, a, b + 1, p + a)) return true;
	S[cur] = 'C';
	if (solve(cur + 1, a, b, p + a + b)) return true;

	return false;
}

int main() {
	// baekjoon 12969

	scanf("%d %d", &N, &K);

	if (solve(0, 0, 0, 0)) {
		for (int i = 0; i < N; i++)
		{
			printf("%c", S[i]);
		}
		printf("\n");
	}
	else
		printf("-1\n");

	getchar();
	getchar();

	return 0;
}