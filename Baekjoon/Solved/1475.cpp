#include <iostream>

using namespace std;

int main()
{
	int count[10] = { 0, };

	int N;
	cin >> N;

	if (N == 0)
	{
		cout << 1 << endl;
		return 0;
	}

	while (N != 0)
	{
		count[N % 10]++;
		N = N / 10;
	}

	count[6] += count[9];
	count[6] = count[6] / 2 + count[6] % 2;

	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		if (max < count[i])
			max = count[i];
	}

	cout << max << endl;

	getchar();
	getchar();

	return 0;
}