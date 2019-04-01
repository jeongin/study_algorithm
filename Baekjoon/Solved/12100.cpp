1#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int board[21][21];
int ans;
int debug = 0;

void print_b(int bb[][21])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%4d ", bb[i][j]);
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

	if (debug == 1)
	{
		printf("===========================\n");
		print_b(b);
	}

	int tmp[21][21];
	copy_board(b, tmp);

	if (dir == 0) // 위쪽
	{
		if (debug == 1)
			printf("up\n");
		for (int i = 0; i < N; i++)
		{
			int k = 0;
			for (int j = 0; j < N - 1; j++)
			{
				if (tmp[j][i] != 0)
				{
					int check = 0;
					for (int l = 1; j + l <= N - 1; l++)
					{
						if (tmp[j + l][i] == 0)
							continue;

						if (tmp[j][i] == tmp[j + l][i])
						{
							tmp[k][i] = tmp[j][i] * 2;
							tmp[j + l][i] = 0;
							j = j + l;
						}
						else
						{
							tmp[k][i] = tmp[j][i];
						}
						check = 1;
						k++;
						break;
					}

					if (check == 0)
					{
						tmp[k][i] = tmp[j][i];
						k++;
					}
				}
			}

			if (tmp[N - 1][i] != 0)
			{
				tmp[k][i] = tmp[N - 1][i];
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
		if (debug == 1)
			printf("right\n");
		for (int i = 0; i < N; i++)
		{
			int k = N - 1;
			for (int j = N - 1; j > 0; j--)
			{
				if (tmp[i][j] != 0)
				{
					int check = 0;
					for (int l = 1; j - l >= 0; l++)
					{
						if (tmp[i][j - l] == 0)
							continue;

						if (tmp[i][j] == tmp[i][j - l])
						{
							tmp[i][k] = tmp[i][j] * 2;
							tmp[i][j - l] = 0;
							j = j - l;
						}
						else
						{
							tmp[i][k] = tmp[i][j];
						}
						check = 1;
						k--;
						break;
					}

					if (check == 0)
					{
						tmp[i][k] = tmp[i][j];
						k--;
					}
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
		if (debug == 1)
			printf("down\n");
		for (int i = 0; i < N; i++)
		{
			int k = N - 1;
			for (int j = N - 1; j > 0; j--)
			{
				if (tmp[j][i] != 0)
				{
					int check = 0;
					for (int l = 1; j - l >= 0; l++)
					{
						if (tmp[j - l][i] == 0)
							continue;

						if (tmp[j][i] == tmp[j - l][i])
						{
							tmp[k][i] = tmp[j][i] * 2;
							tmp[j - l][i] = 0;
							j = j - l;
						}
						else
						{
							tmp[k][i] = tmp[j][i];
						}
						check = 1;
						k--;
						break;
					}

					if (check == 0)
					{
						tmp[k][i] = tmp[j][i];
						k--;
					}
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
		if (debug == 1)
			printf("left\n");
		for (int i = 0; i < N; i++)
		{
			int k = 0;
			for (int j = 0; j < N - 1; j++)
			{
				if (tmp[i][j] != 0)
				{
					int check = 0;
					for (int l = 1; j + l <= N - 1; l++)
					{
						if (tmp[i][j + l] == 0)
							continue;

						if (tmp[i][j] == tmp[i][j + l])
						{
							tmp[i][k] = tmp[i][j] * 2;
							tmp[i][j + l] = 0;
							j = j + l;
						}
						else
						{
							tmp[i][k] = tmp[i][j];
						}
						check = 1;
						k++;
						break;
					}

					if (check == 0)
					{
						tmp[i][k] = tmp[i][j];
						k++;
					}
				}
			}

			if (tmp[i][N - 1] != 0)
			{
				tmp[i][k] = tmp[i][N - 1];
				k++;
			}

			for (int j = k; j <= N - 1; j++)
			{
				tmp[i][j] = 0;
			}
		}
	}

	if (debug == 1)
	{
		print_b(tmp);
		printf("===========================\n");
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