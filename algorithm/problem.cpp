#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	// baekjoon 11725

	int node[100001];
	int p[100001];
	vector<int> adj[100001];

	int N;
	cin >> N;
	
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int parent = q.back(); q.pop();

		for (int i = 0; i < adj[parent].size(); i++)
		{
			int child = adj[parent][i];

			if (!p[child])
			{
				q.push(child);
				p[child] = parent;
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << p[i] << endl;
	}

	getchar();
	getchar();

	return 0;
}