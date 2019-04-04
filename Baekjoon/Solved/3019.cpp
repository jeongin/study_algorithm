#include <iostream>
#include <algorithm>

using namespace std;

int C, P;
int board[100][100];
int height[100];
int num[13];
int ans;

int main() {
	// baekjoon 3019

	scanf("%d %d", &C, &P);

	for (int i = 0; i < C; i++) {
		scanf("%d", &height[i]);
	}

	switch (P) {
	case 1:
		num[0] = 1;
		num[12] = 1;
		break;
	case 2:
		num[1] = 1;
		break;
	case 3:
		num[3] = 1;
		num[7] = 1;
		break;
	case 4:
		num[2] = 1;
		num[8] = 1;
		break;
	case 5:
		num[2] = 1;
		num[3] = 1;
		num[6] = 1;
		num[11] = 1;
		break;
	case 6:
		num[1] = 1;
		num[5] = 1;
		num[6] = 1;
		num[9] = 1;
		break;
	case 7:
		num[1] = 1;
		num[4] = 1;
		num[6] = 1;
		num[10] = 1;
		break;
	}

	int r, rr, rrr;
	for (int i = 0; i < C - 1; i++) {
		r = i + 1;
		rr = i + 2;
		rrr = i + 3;
		ans += num[0];
		if (r < C) {
			if (height[i] == height[r]) ans += num[1];
			else if (height[i] == height[r] - 1) ans += num[2];
			else if (height[i] == height[r] + 1) ans += num[3];
			else if (height[i] == height[r] - 2) ans += num[4];
			else if (height[i] == height[r] + 2) ans += num[5];
		}

		if (rr < C) {
			if (height[i] == height[r] && height[i] == height[rr]) ans += num[6];
			else if (height[i] == height[r] && height[i] == height[rr] - 1) ans += num[7];
			else if (height[i] == height[r] + 1 && height[i] == height[rr] + 1) ans += num[8];
			else if (height[i] == height[r] - 1 && height[i] == height[rr] - 1) ans += num[9];
			else if (height[i] == height[r] && height[i] == height[rr] + 1) ans += num[10];
			else if (height[i] == height[r] + 1 && height[i] == height[rr]) ans += num[11];
		}

		if (rrr < C) {
			if (height[i] == height[r] && height[i] == height[rr] && height[i] == height[rrr]) ans += num[12];
		}
	}

	ans += num[0];

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}