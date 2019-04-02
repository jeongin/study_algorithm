#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXMOVE 5

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N;
int board[20][20];
int ans;

void copyBoard(int a[][20], int b[][20])
{
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp = a[i][j];
			b[i][j] = tmp;
		}
	}
}

void move(int dir)
{
	queue<int> num;

	if (dir == 0 || dir == 2) // UP, DOWN
	{
		for (int i = 0; i < N; i++)
		{
			int j, idx;
			if (dir == 0)
			{
				j = 0;
				idx = 0;
			}
			else
			{
				j = N - 1;
				idx = N - 1;
			}

			while (j >= 0 && j < N)
			{
				if (board[j][i] != 0)
				{
					num.push(board[j][i]);
					board[j][i] = 0;
				}
				j += dx[dir];
			}

			int val;

			while (!num.empty())
			{
				val = num.front();
				num.pop();

				if (board[idx][i] == 0) board[idx][i] = val;
				else if (board[idx][i] == val)
				{
					board[idx][i] = val * 2;
					idx += dx[dir];
				}
				else
				{
					idx += dx[dir];
					board[idx][i] = val;
				}
			}
		}
	}
	else if (dir == 1 || dir == 3) // RIGHT, LEFT
	{
		for (int i = 0; i < N; i++)
		{
			int j, idx;
			if (dir == 3)
			{
				j = 0;
				idx = 0;
			}
			else
			{
				j = N - 1;
				idx = N - 1;
			}

			while (j >= 0 && j < N)
			{
				if (board[i][j] != 0)
				{
					num.push(board[i][j]);
					board[i][j] = 0;
				}
				j += dy[dir];
			}

			int val;

			while (!num.empty())
			{
				val = num.front();
				num.pop();

				if (board[i][idx] == 0) board[i][idx] = val;
				else if (board[i][idx] == val)
				{
					board[i][idx] = val * 2;
					idx += dy[dir];
				}
				else
				{
					idx += dy[dir];
					board[i][idx] = val;
				}
			}
		}
	}
}

void dfs(int depth)
{
	if (depth == MAXMOVE)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] > ans)
					ans = board[i][j];
			}
		}
		return;
	}

	int tmpBoard[20][20];
	copyBoard(board, tmpBoard);

	for (int i = 0; i < 4; i++) // 4 ¹æÇâ
	{
		move(i);
		dfs(depth + 1);
		copyBoard(tmpBoard, board);
	}
}

int main()
{
	// baekjoon 12100 (revise)

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	dfs(0);

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}