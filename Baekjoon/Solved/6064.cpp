#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int M, N, x, y;
	int result, count, check_y;

	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> x >> y;

		result = -1;
		count= x;

		check_y = (x - 1) % N + 1;

		while (1)
		{
			if (count > M * N)
			{
				break;
			}
			if (y == check_y)
			{
				result = count;
				break;
			}

			count += M;
			check_y = (check_y + M - 1) % N + 1;
		}

		cout << result << endl;
	}

	return 0;
}