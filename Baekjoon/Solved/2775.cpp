#include <iostream>

using namespace std;

int how_many_people(int k, int n)
{
	if (k == 0)
		return n;
	else if (n == 1)
		return 1;
	else
		return how_many_people(k - 1, n) + how_many_people(k, n - 1);
}

int main()
{
	int T;

	cin >> T;

	int k, n;

	for (int i = 0; i < T; i++)
	{
		cin >> k >> n;

		cout << how_many_people(k, n) << endl;
	}


	return 0;
}