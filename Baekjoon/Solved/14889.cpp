#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int S[20][20];
int color[20];
int ans;

int score()
{
	int team0 = 0;
	int team1 = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (color[i] == 0 && color[j] == 0)
				team0 += S[i][j];
			if (color[i] == 1 && color[j] == 1)
				team1 += S[i][j];
		}
	}

	if (team0 > team1)
		return team0 - team1;
	else
		return team1 - team0;

}

void team(int n, int what, int cnt_0, int cnt_1)
{
	color[n] = what;
	if (what == 0)
	{
		cnt_0++;
	}
	else
	{
		cnt_1++;
	}

	if (cnt_0 == N / 2 && cnt_1 == N / 2)
	{
		int tmp = score();
		if (ans > tmp)
		{
			ans = tmp;
		}
		return;
	}

	if (cnt_0 < N / 2)
		team(n + 1, 0, cnt_0, cnt_1);
	if (cnt_1 < N / 2)
		team(n + 1, 1, cnt_0, cnt_1);
}

int main()
{
	// baekjoon 14889

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &S[i][j]);
		}
	}

	ans = 987654321;
	team(0, 0, 0, 0);
	team(0, 1, 0, 0);
	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}