#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct tile
{
	int left, right, num;
};

int dx[2][6] = { { -1, 0, 1, 1, 0, -1 },{ -1, 0, 1, 1 , 0, -1 } };
int dy[2][6] = { { 0, 1,0, -1, -1, -1 },{ 1, 1, 1, 0, -1, 0 } };

int N;
tile t[500][500];
int check[500][500];
int visit[250000];
int route[250000];
int cnt = 1;
int ans;
vector<int> adjacent[250000];

void bfs()
{
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	route[1] = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto nx : adjacent[x])
		{
			if (visit[nx]) continue;
			if (ans < nx) ans = nx;
			visit[nx] = 1;
			route[nx] = x;
			q.push(nx);
		}
	}
}

int main()
{
	// baekjoon 5213

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int end = (i % 2) ? N - 1 : N;
		tile tmp_t;
		for (int j = 0; j < end; j++)
		{
			scanf("%d %d", &tmp_t.left, &tmp_t.right);
			tmp_t.num = cnt;
			cnt++;
			t[i][j] = tmp_t;
		}
	}

	int nx, ny;
	for (int i = 0; i < N; i++)
	{
		int end = (i % 2) ? N - 1 : N;
		for (int j = 0; j < end; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				nx = i + dx[i % 2][k];
				ny = j + dy[i % 2][k];

				if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1)
					continue;

				if (nx % 2 && ny == N - 1)
					continue;

				if (check[nx][ny] == 0)
				{
					if (t[i][j].right == t[nx][ny].left && k < 3)
					{
						adjacent[t[i][j].num].push_back(t[nx][ny].num);
					}
					else if (t[i][j].left == t[nx][ny].right && k > 2)
					{
						adjacent[t[i][j].num].push_back(t[nx][ny].num);
					}
				}
			}
		}
	}

	bfs();

	stack<int> routine;
	routine.push(ans);
	while (route[ans]) {
		ans = route[ans];
		routine.push(ans);
	}

	int len = routine.size();
	printf("%d\n", len);
	for (int i = 0; i < len - 1; i++)
	{
		int num = routine.top();
		routine.pop();
		printf("%d ", num);
	}
	printf("%d\n", routine.top());

	getchar();
	getchar();

	return 0;
}