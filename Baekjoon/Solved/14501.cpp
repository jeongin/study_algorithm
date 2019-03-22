#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int DP[16];
int T[15];
int P[15];

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 14501

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int next1 = i + T[i];
		int next2 = i + 1;

		if (next1 <= N) DP[next1] = max(DP[next1], DP[i] + P[i]);
		if (next2 <= N) DP[next2] = max(DP[next2], DP[i]);

		ans = max(ans, max(DP[next1], DP[next2]));
	}

	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}