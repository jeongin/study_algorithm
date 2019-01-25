#include <iostream>
#include <algorithm>

using namespace std;

int fileSize[501];
int sum[501];
int dp[501][501];

void initData()
{
	for (int i = 0; i < 501; i++)
	{
		fileSize[i] = 0;
		sum[i] = 0;
		for (int j = 0; j < 501; j++)
		{
			dp[i][j] = 0;
		}
	}
}

int find_value(int start, int end)
{
	if (dp[start][end])
		return dp[start][end];

	if (start == end)
		return 0;

	dp[start][end] = 987654321;

	for (int i = start; i < end; i++)
	{
		dp[start][end] = min(dp[start][end], find_value(start, i) + find_value(i + 1, end) + sum[end] - sum[start - 1]);
	}

	return dp[start][end];
}

int main()
{
	// baekjoon 11066

	int T, K;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		initData();

		cin >> K;

		for (int k = 0; k < K; k++)
		{
			cin >> fileSize[k];
			sum[k] = sum[k - 1] + fileSize[k];
		}

		int result = find_value(0, K - 1);
		cout << result << endl;

	}

	return 0;
}