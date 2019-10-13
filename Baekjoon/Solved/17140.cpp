#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int r, c, k;
int arr[101][101] = { 0, };
int r_size = 3, c_size = 3;

void row()
{
	int max_c = 0;

	for (int i = 0; i < r_size; i++)
	{
		vector<pair<int, int>> v; // È½¼ö, ¼ýÀÚ
		int check[101] = { 0, };

		for (int j = 0; j < c_size; j++)
		{
			if (arr[i][j] == 0) continue;

			if (check[arr[i][j]] == 0)
			{
				v.push_back(make_pair(1, arr[i][j]));
				check[arr[i][j]] = 1;
			}
			else
			{
				for (int k = 0; k < v.size(); k++)
				{
					if (v[k].second == arr[i][j])
					{
						v[k].first += 1;
						break;
					}
				}
			}
		}

		sort(v.begin(), v.end());

		//		printf("[%d row]\n", i);
		for (int j = 0; j < v.size(); j++)
		{
			arr[i][2 * j] = v[j].second;
			arr[i][2 * j + 1] = v[j].first;
			//			printf("[num %d]: %d\n", v[j].second, v[j].first);
		}

		for (int j = v.size() * 2; j < c_size; j++)
		{
			arr[i][j] = 0;
		}

		if (v.size() * 2 > max_c) max_c = v.size() * 2;

	}

	c_size = max_c;
}

void col()
{
	int max_r = 0;

	for (int i = 0; i < c_size; i++)
	{
		vector<pair<int, int>> v; // È½¼ö, ¼ýÀÚ
		int check[101] = { 0, };

		for (int j = 0; j < r_size; j++)
		{
			if (arr[j][i] == 0) continue;

			if (check[arr[j][i]] == 0)
			{
				v.push_back(make_pair(1, arr[j][i]));
				check[arr[j][i]] = 1;
			}
			else
			{
				for (int k = 0; k < v.size(); k++)
				{
					if (v[k].second == arr[j][i])
					{
						v[k].first += 1;
						break;
					}
				}
			}
		}

		sort(v.begin(), v.end());

		//		printf("[%d col]\n", i);
		for (int j = 0; j < v.size(); j++)
		{
			arr[j * 2][i] = v[j].second;
			arr[j * 2 + 1][i] = v[j].first;
			//			printf("[num %d]: %d\n", v[j].second, v[j].first);
		}

		for (int j = v.size() * 2; j < r_size; j++)
		{
			arr[j][i] = 0;
		}

		if (v.size() * 2 > max_r) max_r = v.size() * 2;

	}

	r_size = max_r;
}

int main(int argc, char** argv) {
	// baekjoon 17140

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	while (cnt <= 100)
	{
		if (arr[r - 1][c - 1] == k) break;

		if (r_size >= c_size) row();
		else col();

		//printf("==================================\n");
		//for (int i = 0; i < r_size; i++)
		//{
		//	for (int j = 0; j < c_size; j++)
		//	{
		//		printf("%d ", arr[i][j]);
		//	}
		//	printf("\n");
		//}

		cnt++;
	}

	if (cnt == 101) printf("-1\n");
	else printf("%d\n", cnt);

	getchar();
	getchar();

	return 0;
}