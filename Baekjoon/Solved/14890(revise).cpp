#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int board[100][100];
int tmp[100];

int slide() {
	int check[100] = { 0 };
	for (int i = 0; i < N - 1; i++) {
		if (tmp[i] == tmp[i + 1]) continue;
		else if (tmp[i] == tmp[i + 1] + 1) { // 오른쪽이 한칸 낮을 때
			if (i + L > N - 1) return 0;

			for (int j = 1; j <= L; j++) {
				if (tmp[i + 1] != tmp[i + j]) return 0;
				if (check[i + j] == 1) return 0;
				check[i + j] = 1;
			}
		}
		else if (tmp[i] == tmp[i + 1] - 1) { // 오른쪽이 한칸 높을 때
			if (i - (L - 1) < 0) return 0;

			for (int j = 0; j <= L - 1; j++) {
				if (tmp[i] != tmp[i - j]) return 0;
				if (check[i - j] == 1) return 0;
				check[i - j] = 1;
			}
		}
		else return 0;
	}

	return 1;
}

int main() {
	// baekjoon 14890

	cin >> N >> L;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
		}
	}

	int ans = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			tmp[y] = board[x][y];
		}
		ans += slide();
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			tmp[x] = board[x][y];
		}
		ans += slide();
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}