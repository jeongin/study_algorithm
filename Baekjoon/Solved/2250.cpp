#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> tree[10001]; // 각 노드의 left, right
vector<int> level[10001]; // 각 레벨에 포함된 노드
int now_column;
int column[10001]; // 노드의 column 값
int max_level; // 트리의 depth
int node[10001];

void inorder(int cur, int cur_level)
{
	if (tree[cur][0] != -1)
		inorder(tree[cur][0], cur_level + 1);

	column[cur] = now_column++;
	level[cur_level].push_back(cur);
	max_level = (max_level < cur_level) ? cur_level : max_level;

	if (tree[cur][1] != -1)
		inorder(tree[cur][1], cur_level + 1);
}

int main()
{
	ios::sync_with_stdio(false);

	// baekjoon 2250

	int N;
	cin >> N;

	int root;
	for (int i = 0; i < N; i++)
	{
		int parent, left, right;
		cin >> parent >> left >> right;
		node[parent]++;

		tree[parent].push_back(left);
		tree[parent].push_back(right);

		if (left != -1)
			node[left]++;
		if (right != -1)
			node[right]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (node[i] == 1)
			root = i;
	}

	now_column = 1;
	inorder(root, 1);

	int ans_level = 1, ans_length = 0;
	for (int i = 1; i <= max_level; i++)
	{
		int level_length = column[level[i].back()] - column[level[i].front()] + 1;
		if (level_length > ans_length)
		{
			ans_length = level_length;
			ans_level = i;
		}
	}

	cout << ans_level << " " << ans_length << "\n";

	getchar();
	getchar();
	return 0;
}