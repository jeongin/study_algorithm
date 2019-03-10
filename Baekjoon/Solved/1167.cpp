#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> node[100001];
int visit[100001];
int ans;
int far_node;

void dfs(int num, int length)
{
	visit[num] = true;

	if (length > ans)
	{
		ans = length;
		far_node = num;
	}

	for (int i = 0; i < node[num].size(); i++)
	{
		if (visit[node[num][i].first] == false)
			dfs(node[num][i].first, node[num][i].second + length);
	}

	visit[num] = false;
}

int main()
{
	ios::sync_with_stdio(false);

	// baekjoon 1167

	int V;
	cin >> V;

	int from, to, length;
	for (int i = 1; i <= V; i++)
	{
		cin >> from;
		to = 0;
		while (1)
		{
			cin >> to;
			if (to == -1)
				break;
			cin >> length;

			node[from].push_back(make_pair(to, length));
		}
	}

	dfs(1, 0);
	ans = 0;
	dfs(far_node, 0);

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}