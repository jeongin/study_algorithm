#include <iostream>
#include <algorithm>

using namespace std;

struct three
{
	int a, b, c;
};

int N;
int scv[3];
int dp[15][60][60][60];
int ans = 15;

three hp(int n1, int n2, int n3) {
	three ret;
	ret.a = n1 - 9;
	ret.b = n2 - 3;
	ret.c = n3 - 1;

	return ret;
}

void attack(int n, int a, int b, int c) {
	if (n > ans)
		return;

	if (a <= 0 && b <= 0 && c <= 0) {
		if (ans > n) {
			ans = n;
		}

		return;
	}

	if (dp[n][a][b][c]) return;

	dp[n][a][b][c] = 1;

	three tmp;
	if (N == 3)
	{
		tmp = hp(a, b, c);
		attack(n + 1, tmp.a, tmp.b, tmp.c);

		tmp = hp(a, c, b);
		attack(n + 1, tmp.a, tmp.c, tmp.b);

		tmp = hp(b, a, c);
		attack(n + 1, tmp.b, tmp.a, tmp.c);

		tmp = hp(b, c, a);
		attack(n + 1, tmp.c, tmp.a, tmp.b);

		tmp = hp(c, a, b);
		attack(n + 1, tmp.b, tmp.c, tmp.a);

		tmp = hp(c, b, a);
		attack(n + 1, tmp.c, tmp.b, tmp.a);
	}
	else if (N == 2)
	{
		tmp = hp(a, b, 0);
		attack(n + 1, tmp.a, tmp.b, 0);

		tmp = hp(b, a, 0);
		attack(n + 1, tmp.b, tmp.a, 0);
	}

}

int main() {
	// baekjoon 12869

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &scv[i]);
	}

	if (N == 1) {
		if (scv[0] % 9 == 0) {
			printf("%d\n", scv[0] / 9);
		}
		else {
			printf("%d\n", scv[0] / 9 + 1);
		}
		return 0;
	}

	attack(0, scv[0], scv[1], scv[2]);

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}