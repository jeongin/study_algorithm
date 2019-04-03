#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string original;
int A, B, C;
int S[50];
int dp[50][50][50][3][3];

bool find(int a, int b, int c, int before1, int before2)
{
	if (a == A && b == B && c == C)
		return true;

	if (dp[a][b][c][before1][before2]) return false;

	dp[a][b][c][before1][before2] = 1;

	if (a < A) {
		S[a + b + c] = 'A';
		if (find(a + 1, b, c, 0, before1)) return true;
	}

	if (b < B && before1 != 1) {
		S[a + b + c] = 'B';
		if (find(a, b + 1, c, 1, before1)) return true;
	}

	if (c < C && before1 != 2 && before2 != 2) {
		S[a + b + c] = 'C';
		if (find(a, b, c + 1, 2, before1)) return true;
	}

	return false;
}

int main() {
	// baekjoon 14238

	cin >> original;
	int len = original.size();
	for (int i = 0; i < len; i++) {
		if (original[i] == 'A')
			A++;
		if (original[i] == 'B')
			B++;
		if (original[i] == 'C')
			C++;
	}

	if (find(0, 0, 0, 0, 0)) {
		for (int i = 0; i < len; i++) {
			printf("%c", S[i]);
		}
		printf("\n");
	}
	else {
		printf("-1\n");
	}

	getchar();
	getchar();

	return 0;
}