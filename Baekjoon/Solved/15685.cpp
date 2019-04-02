#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct dragon
{
	int sx, sy;
	vector<int> dir;
};

// right, up, left, down
int dx[4] = { 1, 0, -1, 0 }; // 가로
int dy[4] = { 0, -1, 0, 1 }; // 세로

int N;
int board[101][101];
dragon d[20];
int max_x, max_y;

void check_board(dragon d)
{
	int x = d.sx;
	int y = d.sy;
	int vec_size = d.dir.size();

	board[y][x] = 1;

	if (x > max_x)
		max_x = x;
	if (y > max_y)
		max_y = y;

	for (int i = 0; i < vec_size; i++)
	{
		x += dx[d.dir[i]];
		y += dy[d.dir[i]];

		board[y][x] = 1;
		if (x > max_x)
			max_x = x;
		if (y > max_y)
			max_y = y;
	}
}

void make_dragon(int g, dragon d)
{
	int vec_size;
	int n_d;
	while (g > 0)
	{
		vec_size = d.dir.size();
		n_d;
		for (int i = 0; i < vec_size; i++)
		{
			n_d = (d.dir[vec_size - i - 1] + 1) % 4;
			d.dir.push_back(n_d);
		}
		g--;
	}

	check_board(d);
}

int main()
{
	// baekjoon 15685

	scanf("%d", &N);
	int x, y, d, g;
	for (int i = 0; i < N; i++)
	{
		dragon tmp_d;
		scanf("%d %d %d %d", &tmp_d.sx, &tmp_d.sy, &d, &g);
		tmp_d.dir.push_back(d);
		make_dragon(g, tmp_d);
	}

	int ans = 0;
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (board[i][j] == 1 && board[i][j + 1] == 1 && board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
				ans++;
		}
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}