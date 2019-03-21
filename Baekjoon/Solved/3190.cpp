#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 }; // 0: 동쪽 1: 남쪽 2: 서쪽 3: 북쪽
int dy[4] = { 1, 0, -1, 0 };
int board[101][101]; // (1,1) 부터 시작

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 3190

	int N, K, L;
	cin >> N >> K;

	int ax, ay; // 사과 좌표
	for (int i = 0; i < K; i++)
	{
		cin >> ax >> ay;
		board[ax][ay] = 1;
	}
	cin >> L;
	queue<pair<int, char>> turn;
	int turn_time;	// 회전 시간
	char turn_direction;	// 회전 방향
	for (int i = 0; i < L; i++)
	{
		cin >> turn_time >> turn_direction;
		turn.push(make_pair(turn_time, turn_direction));
	}


	int time = 0;
	int direction = 0; // 0: 동쪽 1: 남쪽 2: 서쪽 3: 북쪽
	int nx, ny;
	int x = 1, y = 1; // 현재 좌표
	board[x][y] = 2;
	queue<pair<int, int>> bam;
	bam.push(make_pair(x, y));
	int n_time = turn.front().first;
	char n_direction = turn.front().second;
	turn.pop();
	while (1)
	{
		time++;

		nx = x + dx[direction];
		ny = y + dy[direction];

		if (nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 2)
			break;

		if (board[nx][ny] == 0)
		{
			board[bam.front().first][bam.front().second] = 0;
			bam.pop();
		}

		x = nx;
		y = ny;
		board[x][y] = 2;
		bam.push(make_pair(x, y));

		if (time == n_time)
		{
			if (n_direction == 'L')
			{
				direction = (direction + 3) % 4;
			}
			else if (n_direction == 'D')
			{
				direction = (direction + 1) % 4;
			}

			if (turn.size() > 0)
			{
				n_time = turn.front().first;
				n_direction = turn.front().second;
				turn.pop();
			}
		}
	}

	cout << time << "\n";

	getchar();
	getchar();

	return 0;
}