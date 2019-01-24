#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
	// baekjoon 1005

	ios_base::sync_with_stdio(false);
	int T, N, K;
	int X, Y;
	int W;

	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int delay[1001] = { 0, };
		int indegree[1001] = { 0, };
		int DP[1001] = { 0, };
		vector<int> relation[1001];
		queue<int> q;

		memset(delay, 0, sizeof(delay));
		memset(indegree, 0, sizeof(indegree));
		memset(DP, 0, sizeof(DP));
		memset(relation, 0, sizeof(relation));

		cin >> N >> K;

		for (int n = 1; n <= N; n++)
		{
			cin >> delay[n];
		}

		for (int k = 0; k < K; k++)
		{
			cin >> X >> Y;
			relation[X].push_back(Y);
			indegree[Y]++;
		}

		cin >> W;

		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0) q.push(i);
			DP[i] = delay[i];
		}

		while (!q.empty())
		{
			int now = q.front();
			q.pop();

			for (int i = 0; i < relation[now].size(); i++)
			{
				int next = relation[now][i];
				DP[next] = max(DP[next], DP[now] + delay[next]);
				indegree[next]--;
				if (indegree[next] == 0) q.push(next);
			}
		}

		cout << DP[W] << endl;
	}

	return 0;
}