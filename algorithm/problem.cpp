#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int A[1000000];
int B, C;

int main()
{
	ios::sync_with_stdio(false);
	// baekjoon 13458

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> B >> C;

	long long ans = 0;

	for (int i = 0; i < N; i++)
	{
		if (A[i] <= B)
		{
			ans += 1;
		}
		else if ((A[i] - B) % C == 0)
		{
			ans += ((A[i] - B) / C) + 1;
		}
		else
		{
			ans += ((A[i] - B) / C) + 2;
		}
	}
	
	cout << ans << "\n";

	getchar();
	getchar();

	return 0;
}