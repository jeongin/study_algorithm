#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main()
{
	// baekjoon 1912

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> dp[i];
	}

	int max_sum = -999999999;
	for (int i = 0; i < N; i++)
	{
		dp[i] = max(dp[i], dp[i] + dp[i - 1]);
		max_sum = max(max_sum, dp[i]);
	}

	cout << max_sum << endl;

	getchar();
	getchar();

	return 0;
}