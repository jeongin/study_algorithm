#include <iostream>
#include <algorithm>

using namespace std;

int X, Y, K;
int board[13][20];

bool check_line() {
	for (int y = 0; y < Y; y++) {
		int cnt = 0;
		for (int x = 0; x < X - 1; x++) {
			if (board[x][y] == board[x + 1][y]) cnt++;
			else cnt = 0;

			if (cnt == K - 1) break;
		}
		if (cnt < K - 1) return false;
	}

	return true;
}

void copy_board(int a[][20], int b[][20]) {
	for (int x = 0; x < X; x++) {
		for (int y = 0; y < Y; y++) {
			b[x][y] = a[x][y];
		}
	}
}

bool change(int idx, int type, int n) {
	for (int y = 0; y < Y; y++) {
		board[idx][y] = type;
	}

	if (n == 1) {
		return check_line();
	}

	int tmp[13][20];
	copy_board(board, tmp);
	for (int i = idx; i < X; i++) {
		copy_board(tmp, board);
		if (change(i, type, n - 1) == true) return true;
	}

	return false;
}

int main(int argc, char** argv) {
	// samsung 2112

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> X >> Y >> K;
		for (int x = 0; x < X; x++) {
			for (int y = 0; y < Y; y++) {
				cin >> board[x][y];
			}
		}

		int max_add = 0;
		int finish = check_line();
		int tmp[13][20];
		copy_board(board, tmp);
		while (finish == 0) {
			max_add++;
			if (max_add == K) break;

			for (int x = 0; x < X; x++) {
				if (finish == 1) break;
				for (int i = 0; i < 2; i++) {
					copy_board(tmp, board);
					if (change(x, i, max_add) == true) {
						finish = 1;
					}
				}
			}
		}

		cout << "#" << t << " " << max_add << endl;
	}

	getchar();
	getchar();

	return 0;
}