#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int board[8][8];
int v_size;
int ans = 1000000;

vector<pair<int, int>> cctv;

void copy_board(int a[][8], int b[][8])
{
	int tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp = a[i][j];
			b[i][j] = tmp;
		}
	}
}

void count_zero(int a[][8])
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] == 0)
				cnt++;
		}
	}

	if (cnt < ans)
		ans = cnt;
}

void check_board(int b[][8], int x, int y, int up, int right, int down, int left)
{
	if (up == 1)
	{
		for (int i = x - 1; i >= 0; i--)
		{
			if (b[i][y] == 0)
				b[i][y] = 7;
			else if (b[i][y] == 6)
				break;
		}
	}

	if (down == 1)
	{
		for (int i = x + 1; i < N; i++)
		{
			if (b[i][y] == 0)
				b[i][y] = 7;
			else if (b[i][y] == 6)
				break;
		}
	}

	if (left == 1)
	{
		for (int i = y - 1; i >= 0; i--)
		{
			if (b[x][i] == 0)
				b[x][i] = 7;
			else if (b[x][i] == 6)
				break;
		}
	}

	if (right == 1)
	{
		for (int i = y + 1; i < M; i++)
		{
			if (b[x][i] == 0)
				b[x][i] = 7;
			else if (b[x][i] == 6)
				break;
		}
	}
}

void bfs(int idx, int tmp_board[][8])
{
	if (idx == v_size)
	{
		count_zero(tmp_board);
		return;
	}

	int x = cctv[idx].first;
	int y = cctv[idx].second;

	int type = tmp_board[x][y];

	int next_board[8][8];

	switch (type)
	{
	case 1:
		// 合率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 0, 0, 0);
		bfs(idx + 1, next_board);

		// 悼率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 1, 0, 0);
		bfs(idx + 1, next_board);

		// 巢率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 0, 1, 0);
		bfs(idx + 1, next_board);

		// 辑率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 0, 0, 1);
		bfs(idx + 1, next_board);
		break;
	case 2:
		// 合率, 巢率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 0, 1, 0);
		bfs(idx + 1, next_board);

		// 悼率, 辑率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 1, 0, 1);
		bfs(idx + 1, next_board);
		break;
	case 3:
		// 合率, 悼率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 1, 0, 0);
		bfs(idx + 1, next_board);

		// 悼率, 巢率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 1, 1, 0);
		bfs(idx + 1, next_board);

		// 巢率, 辑率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 0, 1, 1);
		bfs(idx + 1, next_board);

		// 辑率, 合率
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 0, 0, 1);
		bfs(idx + 1, next_board);
		break;
	case 4:
		// 合悼巢
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 1, 1, 0);
		bfs(idx + 1, next_board);

		// 悼巢辑
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 0, 1, 1, 1);
		bfs(idx + 1, next_board);

		// 巢辑合
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 0, 1, 1);
		bfs(idx + 1, next_board);

		// 辑合悼
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 1, 0, 1);
		bfs(idx + 1, next_board);
		break;
	case 5:
		// 悼辑巢合
		copy_board(tmp_board, next_board);
		check_board(next_board, x, y, 1, 1, 1, 1);
		bfs(idx + 1, next_board);
		break;
	}


}

int main()
{
	// baekjoon 15683

	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] > 0 && board[i][j] < 6)
			{
				cctv.push_back(make_pair(i, j));
				v_size++;
			}
		}
	}

	int tmp_board[8][8];
	copy_board(board, tmp_board);

	bfs(0, tmp_board);

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}