#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// baekjoon 1024

	int N, L;

	cin >> N >> L;

	int sum = 0;

	if (N % 2 == 0 && L == 2)
		L = 3;

	for (int i = L; i <= 100; i++)
	{
		int K;
		int start;

		if (i % 2 == 0) // Â¦¼ö°³
		{
			K = N / i;
			if (N % i != i / 2) continue;
			start = K - (i - 1) / 2;
		}
		else
		{
			K = N / i;
			if (N % i != 0) continue;
			start = K - (i / 2);
		}

		if (start >= 0)
		{
			for (int j = 0; j < i; j++)
			{
				cout << (start + j) << " ";
			}
			cout << endl;
			return 0;
		}

	}

	cout << "-1" << endl;


	return 0;
}