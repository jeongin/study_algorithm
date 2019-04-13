#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct xyp {
	int x, y, p = 0;
};

struct BC {
	int P, who;
};

int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };

vector<BC> board[10][10];
vector<int> dir[2];
xyp p[2];
int M, A;

int compare(BC a, BC b) {
	return a.P > b.P;
}

void charge() {
	int x0 = p[0].x, y0 = p[0].y;
	int x1 = p[1].x, y1 = p[1].y;

	int b0_size = board[x0][y0].size();
	int b1_size = board[x1][y1].size();

	if (b0_size > 0 && b1_size > 0 && board[x0][y0][0].who == board[x1][y1][0].who) {
		if (b0_size == 1 && b1_size == 1) {
			p[0].p += board[x0][y0][0].P / 2;
			p[1].p += board[x1][y1][0].P / 2;
		}
		else if (b0_size > 1 && b1_size > 1) {
			if (board[x0][y0][1].P > board[x1][y1][1].P) {
				p[0].p += board[x0][y0][1].P;
				p[1].p += board[x1][y1][0].P;
			}
			else {
				p[0].p += board[x0][y0][0].P;
				p[1].p += board[x1][y1][1].P;
			}
		}
		else if (b0_size > 1) {
			p[0].p += board[x0][y0][1].P;
			p[1].p += board[x1][y1][0].P;
		}
		else if (b1_size > 1) {
			p[0].p += board[x0][y0][0].P;
			p[1].p += board[x1][y1][1].P;
		}

		return;
	}

	if (board[x0][y0].size() > 0) p[0].p += board[x0][y0][0].P;
	if (board[x1][y1].size() > 0) p[1].p += board[x1][y1][0].P;

}

int main(int argc, char** argv) {
	// samsung 5644

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				board[x][y].clear();
			}
		}

		cin >> M >> A;
		int dir_in;
		for (int i = 0; i < 2; i++) {
			dir[i].clear();
			for (int j = 0; j < M; j++) {
				cin >> dir_in;
				dir[i].push_back(dir_in);
			}
		}

		int in_x, in_y, in_C, in_P;
		for (int i = 0; i < A; i++) {
			cin >> in_y >> in_x >> in_C >> in_P;
			in_x--, in_y--;
			for (int x = in_x - in_C; x <= in_x + in_C; x++) {
				for (int y = in_y - in_C; y <= in_y + in_C; y++) {
					if (x >= 0 && x < 10 && y >= 0 && y < 10 && abs(x - in_x) + abs(y - in_y) <= in_C)
						board[x][y].push_back({ in_P, i });
				}
			}
		}

		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				if (board[x][y].size() > 1) sort(board[x][y].begin(), board[x][y].end(), compare);
			}
		}

		p[0].x = 0, p[0].y = 0, p[0].p = 0;
		p[1].x = 9, p[1].y = 9, p[1].p = 0;
		charge();
		for (int m = 0; m < M; m++) {
			for (int i = 0; i < 2; i++) {
				p[i].x += dx[dir[i][m]];
				p[i].y += dy[dir[i][m]];
			}
			charge();
		}

		cout << "#" << t << " " << p[0].p + p[1].p << endl;
	}

	getchar();
	getchar();

	return 0;
}