#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N, M; // 세로, 가로
int board[8][8];
int visit[8][8];
vector<pair<int, int>> virus;
int ans;

void copy_board(int from[][8], int to[][8])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp = from[i][j];
			to[i][j] = tmp;
		}
	}
}

void bfs(int x, int y, int board[][8])
{
	int nx[4], ny[4];
	for (int i = 0; i < 4; i++)
	{
		nx[i] = x + dx[i];
		ny[i] = y + dy[i];
		if (nx[i] < 0 || nx[i] >= N || ny[i] < 0 || ny[i] >= M)
			continue;

		if (board[nx[i]][ny[i]] == 0)
		{
			board[nx[i]][ny[i]] = 2;
			bfs(nx[i], ny[i], board);
		}
	}
}

int count_safe(int board[][8])
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void dfs(int x, int y, int cnt)
{
	board[x][y] = 1;
	visit[x][y] = 1;

	if (cnt < 3)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] != 0 || visit[i][j] == 1)
					continue;

				dfs(i, j, cnt + 1);
			}
		}
	}
	else if (cnt == 3)
	{
		int tmp[8][8];
		copy_board(board, tmp);

		for (int i = 0; i < virus.size(); i++)
		{
			bfs(virus[i].first, virus[i].second, board);
		}

		ans = max(ans, count_safe(board));
		copy_board(tmp, board);
	}

	board[x][y] = 0;
	visit[x][y] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 14502

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				dfs(i, j, 1);
			}
		}
	}

	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}