#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
char board[10][10];
int R_x, R_y;
int B_x, B_y;
int O_x, O_y;
int ans = 11;
int debug = 0;

void print_board(char b[][10])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%c ", b[i][j]);
		}
		printf("\n");
	}
}

void copy_board(char a[][10], char b[][10])
{
	char tmp;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			tmp = a[i][j];
			b[i][j] = tmp;
		}
	}
}

pair<int, int> move(int color, int x, int y, char tmp_board[][10], int dir)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	while (tmp_board[nx][ny] == '.')
	{
		tmp_board[x][y] = '.';
		if (color == 0) // Red
		{
			tmp_board[nx][ny] = 'R';
		}
		else // Blue
		{
			tmp_board[nx][ny] = 'B';
		}
		x = nx;
		y = ny;
		nx = x + dx[dir];
		ny = y + dy[dir];
	}

	if (tmp_board[nx][ny] == 'O')
	{
		tmp_board[x][y] = '.';
		return make_pair(nx, ny);
	}

	return make_pair(x, y);
}

void bfs(int cnt, int r_x, int r_y, int b_x, int b_y, char tmp_board[][10], int dir)
{
	if (cnt > 10)
	{
		return;
	}

	if (debug)
	{
		printf("=====================\n");
		printf("cnt: %d\n", cnt);
		print_board(tmp_board);
	}

	int R_goal = 0, B_goal = 0;
	pair<int, int> tmp_xy;
	int order = 0; // blue -> red;
	if (dir == 0 && r_x < b_x) // up
	{
		order = 1;
	}
	else if (dir == 1 && r_y > b_y) // right
	{
		order = 1;
	}
	else if (dir == 2 && r_x > b_x) // down
	{
		order = 1;
	}
	else if (dir == 3 && r_y < b_y) // left
	{
		order = 1;
	}

	if (order)
	{
		tmp_xy = move(0, r_x, r_y, tmp_board, dir);
		r_x = tmp_xy.first;
		r_y = tmp_xy.second;
		tmp_xy = move(1, b_x, b_y, tmp_board, dir);
		b_x = tmp_xy.first;
		b_y = tmp_xy.second;
	}
	else
	{
		tmp_xy = move(1, b_x, b_y, tmp_board, dir);
		b_x = tmp_xy.first;
		b_y = tmp_xy.second;
		tmp_xy = move(0, r_x, r_y, tmp_board, dir);
		r_x = tmp_xy.first;
		r_y = tmp_xy.second;
	}

	if (debug)
	{
		printf("[dir]: %d\n", dir);
		print_board(tmp_board);
		printf("=====================\n");
	}

	if (b_x == O_x && b_y == O_y)
	{
		return;
	}

	if (r_x == O_x && r_y == O_y && ans > cnt)
	{
		ans = cnt;
		return;
	}

	char new_board[10][10];
	for (int i = 0; i < 4; i++)
	{
		if (i == dir)
			continue;

		copy_board(tmp_board, new_board);
		bfs(cnt + 1, r_x, r_y, b_x, b_y, new_board, i);
	}

}

int main()
{
	// baekjoon 13460

	scanf("%d %d", &N, &M);

	string mat[11];
	for (int i = 0; i < N; i++)
	{
		cin >> mat[i];
		for (int j = 0; j < M; j++)
		{
			board[i][j] = mat[i][j];
			if (board[i][j] == 'R')
			{
				R_x = i, R_y = j;
			}
			else if (board[i][j] == 'B')
			{
				B_x = i, B_y = j;
			}
			else if (board[i][j] == 'O')
			{
				O_x = i, O_y = j;
			}
		}
	}

	char tmp_board[10][10];
	for (int i = 0; i < 4; i++)
	{
		copy_board(board, tmp_board);
		bfs(1, R_x, R_y, B_x, B_y, tmp_board, i);
	}

	if (ans == 11)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", ans);
	}

	getchar();
	getchar();

	return 0;
}