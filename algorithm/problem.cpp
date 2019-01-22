#include <iostream>
#include <map>

using namespace std;

int delay[100001];

int main()
{
	// baekjoon 1005

	int T, N, K;
	int X, Y;
	map<int, int> relation;
	int W;

	for (int t = 0; t < T; t++)
	{
		cin >> N >> K;

		for (int n = 1; n <= N; n++)
		{
			cin >> delay[n];
		}

		for (int k = 0; k <= K; k++)
		{
			cin >> X >> Y;
			relation.insert(make_pair(X, Y));
		}

		cin >> W;

	}



	return 0;
}