#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int node[100001];
int p[100001];
vector<int> adj[100001];

void dfs(int cur, int par)
{
	p[cur] = par;
	for (int i = 0; i < adj[cur].size(); i++)
	{
		int nxt = adj[cur][i];
		if (nxt != par)
			dfs(nxt, cur);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	// baekjoon 11725

	int N;
	cin >> N;

	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);

	for (int i = 2; i <= N; i++)
	{
		cout << p[i] << "\n";
	}

	getchar();
	getchar();

	return 0;
}