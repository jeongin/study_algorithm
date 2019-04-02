#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> dak;
int dist[100][13];
int home_size;
int dak_size;
int dak_check[13];
int ans = 2500;

int compare(int a, int b)
{
	return a > b;
}

int distance(int h_x, int h_y, int d_x, int d_y) // 집 x y 치킨집 x y
{
	int absolute_x = (h_x > d_x) ? h_x - d_x : d_x - h_x;
	int absolute_y = (h_y > d_y) ? h_y - d_y : d_y - h_y;

	return absolute_x + absolute_y;
}

void all_distance()
{
	for (int i = 0; i < home_size; i++)
	{
		for (int j = 0; j < dak_size; j++)
		{
			dist[i][j] = distance(home[i].first, home[i].second, dak[j].first, dak[j].second);
		}
	}
}

int get_min_val()
{
	int ret = 0;
	for (int i = 0; i < home_size; i++)
	{
		int min_dist = 50;
		for (int j = 0; j < dak_size; j++)
		{
			if (dak_check[j] == 1)
			{
				if (min_dist > dist[i][j])
					min_dist = dist[i][j];
			}
		}
		ret += min_dist;
	}

	return ret;
}

void dfs(int idx, int cnt)
{
	dak_check[idx] = 1;

	if (cnt == M - 1)
	{
		ans = min(ans, get_min_val());
		dak_check[idx] = 0;
		return;
	}

	int nx, ny;
	for (int i = idx + 1; i < dak_size; i++)
	{
		if (dak_check[i] == 0)
		{
			dfs(i, cnt + 1);
		}
	}

	dak_check[idx] = 0;
}

int main()
{
	// baekjoon 15686

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == 2)
			{
				dak.push_back(make_pair(i, j));
			}
			else if (board[i][j] == 1)
			{
				home.push_back(make_pair(i, j));
			}
		}
	}

	dak_size = dak.size();
	home_size = home.size();

	all_distance();

	for (int i = 0; i < dak_size; i++)
	{
		dfs(i, 0);
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}