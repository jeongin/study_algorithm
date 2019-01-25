#include <iostream>
#include <algorithm>


using namespace std;


int main()
{
	// baekjoon 1934

	int T;
	cin >> T;

	int A, B, C;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;

		int ans = A * B;

		while (A % B != 0)
		{
			C = A % B;
			A = B;
			B = C;
		}

		ans /= B;

		cout << ans << endl;
	}

	return 0;
}