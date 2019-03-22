#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M; //세로, 가로
pair<int, int> figure[19][3];
int board[501][501];

void set_figure()
{
	// figure 0
	figure[0][0] = make_pair(0, 1);
	figure[0][1] = make_pair(0, 2);
	figure[0][2] = make_pair(0, 3);
	figure[1][0] = make_pair(1, 0);
	figure[1][1] = make_pair(2, 0);
	figure[1][2] = make_pair(3, 0);

	// figure 1
	figure[2][0] = make_pair(0, 1);
	figure[2][1] = make_pair(1, 0);
	figure[2][2] = make_pair(1, 1);

	// figure 2
	figure[3][0] = make_pair(0, 1);
	figure[3][1] = make_pair(0, 2);
	figure[3][2] = make_pair(1, 0);
	figure[4][0] = make_pair(0, 1);
	figure[4][1] = make_pair(1, 1);
	figure[4][2] = make_pair(2, 1);
	figure[5][0] = make_pair(1, 0);
	figure[5][1] = make_pair(2, 0);
	figure[5][2] = make_pair(2, 1);
	figure[6][0] = make_pair(0, 1);
	figure[6][1] = make_pair(0, 2);
	figure[6][2] = make_pair(-1, 2);

	figure[7][0] = make_pair(0, 1);
	figure[7][1] = make_pair(1, 0);
	figure[7][2] = make_pair(2, 0);
	figure[8][0] = make_pair(0, 1);
	figure[8][1] = make_pair(0, 2);
	figure[8][2] = make_pair(1, 2);
	figure[9][0] = make_pair(1, 0);
	figure[9][1] = make_pair(1, 1);
	figure[9][2] = make_pair(1, 2);
	figure[10][0] = make_pair(0, 1);
	figure[10][1] = make_pair(-1, 1);
	figure[10][2] = make_pair(-2, 1);

	// figure 3
	figure[11][0] = make_pair(1, 0);
	figure[11][1] = make_pair(1, 1);
	figure[11][2] = make_pair(2, 1);
	figure[12][0] = make_pair(0, 1);
	figure[12][1] = make_pair(-1, 1);
	figure[12][2] = make_pair(-1, 2);
	figure[13][0] = make_pair(1, 0);
	figure[13][1] = make_pair(1, -1);
	figure[13][2] = make_pair(2, -1);
	figure[14][0] = make_pair(0, 1);
	figure[14][1] = make_pair(1, 1);
	figure[14][2] = make_pair(1, 2);

	// figure 4
	figure[15][0] = make_pair(0, 1);
	figure[15][1] = make_pair(0, 2);
	figure[15][2] = make_pair(1, 1);
	figure[16][0] = make_pair(0, 1);
	figure[16][1] = make_pair(-1, 1);
	figure[16][2] = make_pair(1, 1);
	figure[17][0] = make_pair(1, 0);
	figure[17][1] = make_pair(1, -1);
	figure[17][2] = make_pair(1, 1);
	figure[18][0] = make_pair(1, 0);
	figure[18][1] = make_pair(2, 0);
	figure[18][2] = make_pair(1, 1);

}

int get_sum(int x, int y, int idx)
{
	int x1, x2, x3, y1, y2, y3;
	x1 = x + figure[idx][0].first;
	y1 = y + figure[idx][0].second;
	x2 = x + figure[idx][1].first;
	y2 = y + figure[idx][1].second;
	x3 = x + figure[idx][2].first;
	y3 = y + figure[idx][2].second;

	if (x1 < 0 || x1 >= N || x2 < 0 || x2 >= N || x3 < 0 || x3 >= N
		|| y1 < 0 || y1 >= M || y2 < 0 || y2 >= M || y3 < 0 || y3 >= M)
		return -1;

	return (board[x][y] + board[x1][y1] + board[x2][y2] + board[x3][y3]);
}

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 14500

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	set_figure();

	int tmp;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 19; k++)
			{
				tmp = get_sum(i, j, k);
				ans = max(ans, tmp);
			}
		}
	}

	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}