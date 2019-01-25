#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// baekjoon 13241

	long long int A, B, C;

	cin >> A >> B;

	long long int ans = A * B;

	while (A % B != 0)
	{
		C = A % B;
		A = B;
		B = C;
	}

	ans /= B;
	cout << ans << endl;

	getchar();
	getchar();
	return 0;
}