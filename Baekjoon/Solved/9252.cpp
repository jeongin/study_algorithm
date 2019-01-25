#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int dp[1001][1001];
string str[1001][1001];
char str0[1001];
char str1[1001];

int main()
{
	// baekjoon 9252

	cin >> str0;
	cin >> str1;

	int len0 = strlen(str0);
	int len1 = strlen(str1);

	for (int i = 0; i < len0; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (str0[i] == str1[j])
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
					str[i][j] += str0[i];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
					str[i][j] = str[i - 1][j - 1] + str0[i];
				}
			}
			else
			{
				if (i != 0 && j != 0)
				{
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
					str[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? str[i - 1][j] : str[i][j - 1];

				}
				else if (i == 0)
				{
					dp[i][j] = dp[i][j - 1];
					str[i][j] = str[i][j - 1];
				}
				else if (j == 0)
				{
					dp[i][j] = dp[i - 1][j];
					str[i][j] = str[i - 1][j];
				}
			}
		}
	}

	cout << dp[len0 - 1][len1 - 1] << endl;
	cout << str[len0 - 1][len1 - 1] << endl;

	getchar();
	getchar();

	return 0;
}