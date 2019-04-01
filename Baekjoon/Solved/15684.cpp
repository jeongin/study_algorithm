#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, H; // N: 세로선 M: 사다리 갯수 H: 가로선
int board[31][11];
int check;
int debug = 0;

void print_ladder(int a[31][11])
{
	printf("=============================\n");
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void copy_board(int a[31][11], int b[31][11])
{
	int tmp;
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			tmp = a[i][j];
			b[i][j] = tmp;
		}
	}
}

int check_ladder(int tmp_b[31][11])
{
	for (int i = 1; i <= N; i++)
	{
		int x = 0, y = i;

		while (x < H + 1)
		{
			x++;
			if (tmp_b[x][y] == 1)
			{
				if (y == 1)
				{
					if (tmp_b[x][y + 1] == 1)
					{
						y = y + 1;
					}
				}
				else if (y == N)
				{
					if (tmp_b[x][y - 1] == 1)
					{
						y = y - 1;
					}
				}
				else
				{
					if (tmp_b[x][y - 1] == 1 && tmp_b[x][y + 1] == 1)
					{
						int right = 0;
						for (int j = y + 1; j <= N; j++)
						{
							if (tmp_b[x][j] == 1)
								right++;
						}

						if (right % 2 == 1)
						{
							y = y + 1;
						}
						else
						{
							y = y - 1;
						}
					}
					else if (tmp_b[x][y + 1] == 1)
					{
						y = y + 1;
					}
					else if (tmp_b[x][y - 1] == 1)
					{
						y = y - 1;
					}
				}


			}
		}

		if (debug)
			printf("[%d]: %d\n", i, y);
		if (i != y)
			return 0;
	}

	return 1;
}

void find_ladder(int cnt, int ladder[31][11])
{

	if (cnt == 0)
	{
		if (debug)
		{
			print_ladder(ladder);
		}
		check = check_ladder(ladder);
		return;
	}

	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (ladder[i][j] == 0 && ladder[i][j + 1] == 0)
			{
				ladder[i][j] = 1;
				ladder[i][j + 1] = 1;

				find_ladder(cnt - 1, ladder);

				if (check == 1)
				{
					return;
				}

				ladder[i][j] = 0;
				ladder[i][j + 1] = 0;
			}
		}
	}
}

int main()
{
	// baekjoon 15684

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%d", &H);

	int row, column;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &row);
		scanf("%d", &column);
		board[row][column] = 1;
		board[row][column + 1] = 1;
	}

	int val = 0;
	while (1)
	{
		int tmp_board[31][11];
		copy_board(board, tmp_board);
		find_ladder(val, tmp_board);
		if (check == 1)
			break;

		val++;
		if (val > 3)
		{
			printf("-1\n");
			getchar();
			getchar();
			return 0;
		}
	}

	printf("%d\n", val);

	getchar();
	getchar();

	return 0;
}