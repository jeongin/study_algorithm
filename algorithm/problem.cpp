#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, L;
int board[100][100];
int ans;

int check_row(int idx, int row[100], int check[100])
{
	if (idx >= N-1)
	{
		return 1;
	}

	if (idx < N-1)
	{
		if (row[idx] == row[idx + 1]) // 높이 같을 때
		{
			return 1;
		}
		else if (row[idx] == row[idx + 1] + 1) // 오른쪽이 한 칸 낮을 때
		{
			for (int i = 1; i <= L; i++)
			{
				if (i + idx == N)
					return 0;

				if (row[idx + i] != row[idx + 1])
					return 0; 
			}

			for (int i = 1; i <= L; i++)
			{
				check[idx + i] = 1;
			}

			return check_row(idx + L + 1, row, check);
		}
		else if (row[idx] == row[idx + 1] - 1) // 오른쪽이 한 칸 높을 때
		{
			for (int i = 1; i < L; i++)
			{
				if (row[idx - i] != row[idx])
					return 0;
			}

			for (int i = 0; i < L; i++)
			{
				check[idx - i] = 1;
			}

			return check_row(idx + L + 1, row, check);
		}
		else
		{
			return 0;
		}
	}
}

int check_col(int idx, int col[100])
{

}

int main()
{
	// baekjoon 14890

	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int check_r[100] = { 0, };
		int check_c[100] = { 0, };
	}
	
	getchar();
	getchar();

	return 0;
}