#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int N;
int num[100];
int op[4];
vector<int> ans;

using namespace std;

int cal(int a, int b,  int n, int cnt)
{
	if (op[n] == 0)
		return 0;

	op[n]--;

	int result;
	if (n == 0)
	{
		result = a + b;
	}
	else if (n == 1)
	{
		result = a - b;
	}
	else if (n == 2)
	{
		result = a * b;
	}
	else
	{
		if (b < 0)
		{
			result = (a / ((-1) * b)) * (-1);
		}
		else
		{
			result = a / b;
		}
	}

	op[n]++;
	if (cnt == N - 1)
	{
		ans.push_back(result);
		return 0;
	}

	for (int i = 0; i < 4; i++)
	{
		cal(result, num[cnt + 1], i, cnt + 1);
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 14888

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cal(num[0], num[1], i, 1);
	}

	sort(ans.begin(), ans.end());

	cout << ans[0] << "\n";
	cout << ans[ans.size() - 1] << "\n";


	return 0;
}