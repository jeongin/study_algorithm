#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

char l_node[26];
char r_node[26];

void pre(int idx)
{
	cout << char(idx + 'A');

	if (l_node[idx] != '.')
	{
		pre(l_node[idx] - 'A');
	}

	if (r_node[idx] != '.')
	{
		pre(r_node[idx] - 'A');
	}
}

void mid(int idx)
{
	if (l_node[idx] != '.')
	{
		mid(l_node[idx] - 'A');
	}

	cout << char(idx + 'A');

	if (r_node[idx] != '.')
	{
		mid(r_node[idx] - 'A');
	}
}

void post(int idx)
{
	if (l_node[idx] != '.')
	{
		post(l_node[idx] - 'A');
	}

	if (r_node[idx] != '.')
	{
		post(r_node[idx] - 'A');
	}

	cout << char(idx + 'A');
}

int main()
{
	// baekjoon 1991

	int N;
	cin >> N; // # of node

	char parent, l, r;
	for (int i = 0; i < N; i++)
	{
		cin >> parent >> l >> r;
		int idx = parent - 'A';
		l_node[idx] = l;
		r_node[idx] = r;
	}

	pre(0);
	cout << endl;
	mid(0);
	cout << endl;
	post(0);
	cout << endl;

	getchar();
	getchar();

	return 0;
}