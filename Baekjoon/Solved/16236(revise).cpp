#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct shark {
	int x, y, size, eat;
};

struct piii {
	int x, y, dist;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int N;
shark s;
int next_s[2];
int board[20][20];
int check[20][20];

int find_fish() {
	queue<piii> q;
	check[s.x][s.y] = 1;
	q.push({ s.x, s.y, 0 });

	int x, y, d;
	int nx, ny, nd;
	int min_d = 0x7fffffff;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, d = q.front().dist;
		q.pop();

		if (d > min_d) continue;

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i], nd = d + 1;
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && check[nx][ny] == 0) {
				check[nx][ny] = 1;
				if (board[nx][ny] == s.size || board[nx][ny] == 0) {
					q.push({ nx, ny, nd });
				}
				else if (board[nx][ny] < s.size) {
					if (nd < min_d) {
						min_d = nd;
						next_s[0] = nx, next_s[1] = ny;
						q.push({ nx, ny, nd });
					}
					else if (nd == min_d) {
						if ((nx < next_s[0]) || (nx == next_s[0] && ny < next_s[1])) {
							next_s[0] = nx, next_s[1] = ny;
							q.push({ nx, ny, nd });
						}
					}
				}
			}
		}
	}

	if (min_d != 0x7fffffff) return min_d;
	else return 0;
}

int main() {
	// baekjoon 16236 16:20 ½ÃÀÛ

	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> board[x][y];
			if (board[x][y] == 9) {
				board[x][y] = 0;
				s.x = x, s.y = y, s.size = 2, s.eat = 0;
			}
		}
	}

	int t = 0;
	int dist;
	int ans = 0;
	while (1) {
		dist = find_fish();
		if (dist == 0) break;

		ans += dist;
		board[s.x][s.y] = 0;
		s.x = next_s[0], s.y = next_s[1]; s.eat++;
		board[s.x][s.y] = 9;
		if (s.eat == s.size) {
			s.size += 1, s.eat = 0;
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				check[x][y] = 0;
			}
		}
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}