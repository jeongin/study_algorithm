#include <iostream>
#include <string>

using namespace std;


int main()
{
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	string week[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

	int day_sum = 0;

	int x, y;
	cin >> x >> y;

	for (int i = 1; i < x; i++)
	{
		day_sum += days[i];
	}

	day_sum += y;

	cout << week[day_sum % 7] << endl;

	getchar();
	getchar();

	return 0;
}