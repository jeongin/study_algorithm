#include <iostream>

using namespace std;


int main()
{
	int T;
	cin >> T;

	int M, N, x, y;
	int count, check_y, first_y;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;

		count = x;

		if (x > N)
		{
			first_y = x & N;
		}
		else
		{
			first_y = x;
		}

		check_y = first_y;

		while (1)
		{
			if (y == check_y)
			{
				cout << count << endl;
				break;
			}

			count += M;
			check_y = (check_y + M) % N;

			if (check_y == 0)
				check_y = N;

			if (first_y == check_y)
			{
				cout << -1 << endl;
				break;
			}
		}
	}

	return 0;
}