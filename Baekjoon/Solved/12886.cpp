#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int A, B, C;
int check[1000][1000];
int sum;

int main() {
	// baekjoon 12886

	scanf("%d %d %d", &A, &B, &C);
	sum = A + B + C;

	if (sum % 3 != 0) {
		printf("0\n");
		return 0;
	}

	queue<pair<int, int>> q;
	q.push(make_pair(A, B));

	int a, b, c;
	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		c = sum - a - b;
		q.pop();

		check[a][b] = 1;

		if (a == b && b == c) {
			printf("1\n");
			return 0;
		}

		int left[] = { a, a, b };
		int right[] = { b, c, c };

		int tmp;
		int n1, n2, n3;
		for (int i = 0; i < 3; i++) {
			n1 = left[i];
			n2 = right[i];
			if (n1 < n2) {
				n2 -= n1;
				n1 += n1;
			}
			else if (n1 > n2) {
				n1 -= n2;
				n2 += n2;
			}
			n3 = sum - n1 - n2;
			int X = min(n1, min(n2, n3));
			int Y = max(n1, max(n2, n3));
			if (check[X][Y] != 1) {
				q.push(make_pair(X, Y));
			}
		}
	}

	printf("0\n");

	getchar();
	getchar();

	return 0;
}