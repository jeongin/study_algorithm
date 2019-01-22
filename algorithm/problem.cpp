#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int delay[1001] = { 0, };
int DP[1001] = { 0, };
vector<int> relation[1001];

int find_value(int W)
{	
	if (DP[W])
		return DP[W];

	if (relation[W].size() == 0)
		return delay[W];

	int max_val = 0;
	for (int i = 0; i < relation[W].size(); i++)
	{
		max_val = max(max_val, find_value(relation[W][i]));
	}

	DP[W] = delay[W] + max_val;
	return DP[W];
}

int main()
{
	// baekjoon 1005

	int T, N, K;
	int X, Y;
	int W;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 1001; i++)
		{
			delay[i] = 0;
			DP[i] = 0;
			relation[i].clear();
		}

		cin >> N >> K;

		for (int n = 1; n <= N; n++)
		{
			cin >> delay[n];
		}

		for (int k = 0; k < K; k++)
		{
			cin >> X >> Y;
			relation[Y].push_back(X);
		}

		cin >> W;

		int result = find_value(W);

		cout << result << endl;
	}

	return 0;
}