#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int board[50][50];
int N, M; // 技肺, 啊肺
int sx, sy, sdir;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 }; // 0: 合率 1: 悼率 2: 巢率 3: 辑率

int clean(int x, int y, int dir)
{
	int ndir;
	int nx, ny;
	int flag;
	int cnt = 0;
	while (1)
	{
		flag = false;
		if (board[x][y] != 2)
		{
			board[x][y] = 2;
			cnt++;
		}

		for (int i = 0; i < 4; i++)
		{
			ndir = (dir + 3 + 3 * i) % 4;
			nx = x + dx[ndir];
			ny = y + dy[ndir];

			if (board[nx][ny] == 0)
			{
				dir = ndir;
				x = nx;
				y = ny;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			nx = x - dx[dir];
			ny = y - dy[dir];
			if (board[nx][ny] == 1)
				return cnt;

			x = nx;
			y = ny;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 14503

	cin >> N >> M >> sx >> sy >> sdir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << clean(sx, sy, sdir) << "\n";

	getchar();
	getchar();

	return 0;
}