#include <iostream>

using namespace std;

int main()
{
	int T, height, width, nth;

	cin >> T;

	int left, right;
	int sum;

	for (int i = 0; i < T; i++)
	{
		cin >> height >> width >> nth;

		if (nth % height == 0)
		{
			left = height * 100;
			right = (nth / height);
		}
		else
		{
			left = (nth % height) * 100;
			right = (nth / height) + 1;
		}
		sum = left + right;

		cout << sum << endl;

	}

	return 0;
}