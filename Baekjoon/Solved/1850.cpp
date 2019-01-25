#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// baekjoon 1850
	long long int A, B, C;

	cin >> A >> B;

	while (A % B != 0)
	{
		C = A % B;
		A = B;
		B = C;
	}

	while (B != 0)
	{
		cout << "1";
		B--;
	}

	cout << endl;

	getchar();
	getchar();
	return 0;
}