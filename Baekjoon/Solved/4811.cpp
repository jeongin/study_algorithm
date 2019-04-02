#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N;
long long dp[30][30];

unsigned long long eat(int w, int h)
{
	if (dp[w][h] != 0 && w > 0)
		return dp[w][h];

	if (w == 0)
	{
		dp[w][h] = 1;
	}
	else
	{
		dp[w][h] += eat(w - 1, h + 1);
		if (h >= 1)
			dp[w][h] += eat(w, h - 1);
	}

	return dp[w][h];
}

int main()
{
	// baekjoon 4811

	dp[1][0] = 1;
	dp[0][1] = 1;

	scanf("%d", &N);
	while (N > 0)
	{
		printf("%lld\n", eat(N - 1, 1));
		scanf("%d", &N);
	}

	getchar();
	getchar();

	return 0;
}