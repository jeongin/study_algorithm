#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dragon {
	int x, y;
	vector<int> d;
};

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int N;
int board[101][101];

int main() {
	// baekjoon 15685

	cin >> N;

	int d, g;
	int mx = 0, my = 0;
	while (N-- > 0) {
		dragon D;
		cin >> D.x >> D.y >> d >> g;
		D.d.push_back(d);

		while (g-- > 0) {
			int size = D.d.size();
			for (int i = size - 1; i >= 0; i--) {
				D.d.push_back((D.d[i] + 1) % 4);
			}
		}

		int x = D.x, y = D.y;
		if (mx < x) mx = x;
		if (my < y) my = y;
		board[y][x] = 1;
		int size = D.d.size();
		for (int i = 0; i < size; i++) {
			x += dx[D.d[i]], y += dy[D.d[i]];
			if (mx < x) mx = x;
			if (my < y) my = y;
			board[y][x] = 1;
		}
	}

	int cnt = 0;
	for (int yy = 0; yy <= my; yy++) {
		for (int xx = 0; xx <= mx; xx++) {
			if (board[yy][xx] && board[yy][xx + 1] && board[yy + 1][xx] && board[yy + 1][xx + 1]) cnt++;
		}
	}

	cout << cnt << endl;

	getchar();
	getchar();

	return 0;
}