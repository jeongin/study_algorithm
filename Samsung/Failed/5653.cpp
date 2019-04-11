#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct xy {
	int x, y;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int H, W, K;
int state[400][400]; // 1: 비활성 2: 활성 3: 죽은
int year[400][400];
int life[400][400];
int check[400][400];

int main(int argc, char** argv) {
	// samsung 5653

	int test_case;
	int T;

	freopen("sample_input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> H >> W >> K;
		queue<xy> q;
		int tmp;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				cin >> tmp;
				if (tmp > 0) {
					state[200 + x][200 + y] = 1;
					life[200 + x][200 + y] = tmp;
					check[200 + x][200 + y] = 1;
					q.push({ 200 + x, 200 + y });
				}
			}
		}

		int min_x = 200, min_y = 200;
		int max_x = 200 + H - 1, max_y = 200 + W - 1;

		queue<xy> nq;

		while (K-- > 0) {
			while (!q.empty()) {
				nq.push(q.front());
				q.pop();
			}

			while (!nq.empty()) {
				int x = nq.front().x, y = nq.front().y; nq.pop();

				if (state[x][y] == 2 && year[x][y] == 0) {
					cout << "(" << x << ", " << y << ")" << endl;
					int nx, ny;
					for (int i = 0; i < 4; i++) {
						nx = x + dx[i], ny = y + dy[i];
						if (nx < min_x) min_x = nx;
						if (nx > max_x) max_x = nx;
						if (ny < min_y) min_y = ny;
						if (ny > max_y) max_y = ny;

						if (check[nx][ny] == 0) {
							check[nx][ny] = 1;
							state[nx][ny] = 1;
							life[nx][ny] = life[x][y];
							q.push({ nx,ny });
						}
						else if (check[nx][ny] == 1 && state[nx][ny] == 1 && year[nx][ny] == 0 && life[nx][ny] < life[x][y]) {
							life[nx][ny] = life[x][y];
						}
					}
				}

				if ((state[x][y] == 1 || state[x][y] == 2) && life[x][y] > 0) year[x][y]++;

				if (state[x][y] == 1 && life[x][y] == year[x][y]) {
					state[x][y] = 2;
					year[x][y] = 0;
					q.push({ x,y });
				}
				else if (state[x][y] == 2 && life[x][y] == year[x][y]) {
					state[x][y] = 3;
					year[x][y] = 0;
				}
				else q.push({ x,y });
			}

			cout << "\n[K]: " << K << endl;
			cout << "========[year]=========" << endl;
			for (int x = min_x; x <= max_x; x++) {
				for (int y = min_y; y <= max_y; y++) {
					cout << year[x][y] << " ";
				}
				cout << endl;
			}

			cout << "========[state]=========" << endl;
			for (int x = min_x; x <= max_x; x++) {
				for (int y = min_y; y <= max_y; y++) {
					cout << state[x][y] << " ";
				}
				cout << endl;
			}

			cout << "========[life]=========" << endl;
			for (int x = min_x; x <= max_x; x++) {
				for (int y = min_y; y <= max_y; y++) {
					cout << life[x][y] << " ";
				}
				cout << endl;
			}

			int aaaa = 0;
		}

		int cnt = 0;
		for (int x = 0; x < 400; x++) {
			for (int y = 0; y < 400; y++) {
				if (state[x][y] < 3 && life[x][y] > 0) cnt++;
				check[x][y] = 0;
				state[x][y] = 0;
				year[x][y] = 0;
				life[x][y] = 0;
			}
		}

		cout << "#" << test_case << " " << cnt << "\n";
	}

	getchar();
	getchar();

	return 0;
}