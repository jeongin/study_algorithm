#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>

using namespace std;

deque<int> T[4];
int K;
queue<pair<int, int>> rotation;

void rotate(int num, int dir)
{
	int tmp;
	if (dir == -1)
	{
		tmp = T[num].front();
		T[num].pop_front();
		T[num].push_back(tmp);
	}
	else if (dir == 1)
	{
		tmp = T[num].back();
		T[num].pop_back();
		T[num].push_front(tmp);
	}
}

void left_check(int num, int dir) // dir = 1 시계방향, dir = -1 반시계방향
{
	if (num <= 0)
		return;

	if (num > 0)
	{
		if (T[num][6] != T[num - 1][2])
		{
			left_check(num - 1, dir * -1);

			rotate(num - 1, dir * -1);
		}
	}
}

void right_check(int num, int dir)
{
	if (num >= 3)
		return;

	if (num < 3)
	{
		if (T[num][2] != T[num + 1][6])
		{
			right_check(num + 1, dir * -1);

			rotate(num + 1, dir * -1);
		}
	}
}

int main()
{
	// baekjoon 14891

	string tmp;
	for (int i = 0; i < 4; i++)
	{
		cin >> tmp;
		for (int j = 0; j < 8; j++)
		{
			T[i].push_back(tmp[j] - 48);
		}
	}

	cin >> K;
	int num, dir;
	for (int i = 0; i < K; i++)
	{
		cin >> num >> dir;
		rotation.push(make_pair(num - 1, dir));
	}

	while (!rotation.empty())
	{
		num = rotation.front().first;
		dir = rotation.front().second;
		rotation.pop();

		left_check(num, dir);
		right_check(num, dir);
		rotate(num, dir);
	}

	int ans = 0;
	int mul[4] = { 1, 2, 4, 8 };
	for (int i = 0; i < 4; i++)
	{
		if (T[i].front() == 1)
		{
			ans += mul[i];
		}
	}

	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}