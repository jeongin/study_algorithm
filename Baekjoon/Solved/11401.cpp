#include <iostream>

using namespace std;

#define P 1000000007

long long factorial[4000000];

long long power(long long a, long long b)
{
	if (b == 0)
		return 1;

	long long n = power(a, b / 2);
	long long temp = (n * n) % P;

	if (b % 2 == 0)
		return temp;
	else
		return (temp * a) % P;
}

int main()
{
	int N, K;

	cin >> N >> K;

	factorial[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		factorial[i] = (factorial[i - 1] * i) % P;
	}

	long long inverse_N_minus_K = power(factorial[N - K], P - 2);
	long long inverse_K = power(factorial[K], P - 2);

	long long result = factorial[N];
	result = (result * inverse_N_minus_K) % P;
	result = (result * inverse_K) % P;

	cout << result << endl;

	return 0;
}