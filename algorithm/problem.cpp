#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int board[21][21];
int ans;

void print_b(int bb[][21])
{
	printf("===========================\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", bb[i][j]);
		}
		printf("\n");
	}
}

void copy_board(int a[][21], int b[][21])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void solve(int depth, int b[][21], int dir) // dir <- 0: 위쪽 1: 오른쪽 2: 아래쪽 3: 왼쪽
{
	//print_b(b);

	if (depth == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (b[i][j] > ans)
					ans = b[i][j];
			}
		}
		return;
	}

	int tmp[21][21];
	copy_board(b, tmp);

	if (dir == 0) // 위쪽
	{
		for (int i = 0; i < N; i++)
		{
			int k = 0;
			for (int j = 0; j < N - 1; j++)
			{
				if (tmp[j][i] == tmp[j + 1][i] && tmp[j][i] != 0)
				{
					tmp[k][i] = tmp[j][i] * 2;
					tmp[j + 1][i] = 0;
					j++;
					k++;
				}
				else if(tmp[j][i] != 0)
				{
					tmp[k][i] = tmp[j][i];
					k++;
				}
			}

			if (tmp[N-1][i] != 0)
			{
				tmp[k][i] = tmp[N-1][i];
				k++;
			}

			for (int j = k; j < N; j++)
			{
				tmp[j][i] = 0;
			}
		}
	}
	else if (dir == 1) // 오른쪽
	{
		for (int i = 0; i < N; i++)
		{
			int k = N - 1;
			for (int j = N-1; j > 0; j--)
			{
				if (tmp[i][j] == tmp[i][j-1] && tmp[i][j] != 0)
				{
					tmp[i][k] = tmp[i][j] * 2;
					tmp[i][j - 1] = 0;
					j--;
					k--;
				}
				else if(tmp[i][j] != 0)
				{
					tmp[i][k] = tmp[i][j];
					k--;
				}
			}
			
			if (tmp[i][0] != 0)
			{
				tmp[i][k] = tmp[i][0];
				k--;
			}

			for (int j = k; j >= 0; j--)
			{
				tmp[i][j] = 0;
			}
		}
	}
	else if (dir == 2) // 아래쪽
	{
		for (int i = 0; i < N; i++)
		{
			int k = N - 1;
			for (int j = N-1; j > 0; j--)
			{
				if (tmp[j][i] == tmp[j - 1][i] && tmp[j][i] != 0)
				{
					tmp[k][i] = tmp[j][i] * 2;
					tmp[j - 1][i] = 0;
					j--;
					k--;
				}
				else if(tmp[j][i] != 0)
				{
					tmp[k][i] = tmp[j][i];
					k--;
				}
			}

			if (tmp[0][i] != 0)
			{
				tmp[k][i] = tmp[0][i];
				k--;
			}

			for (int j = k; j >= 0; j--)
			{
				tmp[j][i] = 0;
			}
		}
		
	}
	else if (dir == 3) // 왼쪽
	{
		for (int i = 0; i < N; i++)
		{
			int k = 0;
			for (int j = 0; j < N-1; j++)
			{
				if (tmp[i][j] == tmp[i][j + 1] && tmp[i][j] != 0)
				{
					tmp[i][k] = tmp[i][j] * 2;
					tmp[i][j + 1] = 0;
					j++;
					k++;
				}
				else if(tmp[i][j] != 0)
				{
					tmp[i][k] = tmp[i][j];
					k++;
				}
			}

			if (tmp[i][N - 1] != 0)
			{
				tmp[i][k] = tmp[i][N - 1];
				k++;
			}

			for (int j = k; j >= 0; j--)
			{
				tmp[i][j] = 0;
			}
		}
	}

	int new_board[21][21];
	for (int i = 0; i < 4; i++)
	{
		copy_board(tmp, new_board);

		solve(depth + 1, new_board, i);
	}
}

int main()
{
	// baekjoon 12100

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		solve(0, board, i);
	}

	printf("%d\n", ans);
	
	getchar();
	getchar();

	return 0;
}