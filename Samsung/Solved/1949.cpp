#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct xy {
	int x, y;
};

struct road {
	int x, y, dist;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, K;
int mountain[8][8];
vector<xy> top;
int ans;

void bfs(int x, int y) {
	/*cout << "==========================\n" << endl;
	for (int x = 0; x < N; x++) {
	for (int y = 0; y < N; y++) {
	cout << mountain[x][y] << " ";
	}
	cout << endl;
	}*/

	queue<road> q;
	q.push({ x, y, 1 });

	int nx, ny, ndist;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y, ndist = q.front().dist + 1;
		q.pop();

		//cout << "[x]: " << x << " [y]: " << y << " [dist]: " << ndist - 1 << endl;

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && mountain[x][y] > mountain[nx][ny]) {
				q.push({ nx, ny, ndist });
				if (ndist > ans) ans = ndist;
			}
		}
	}
}

int main(int argc, char** argv) {
	// samsung 1949 10:40 start 11:40 end

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;

		int max = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> mountain[x][y];
				if (mountain[x][y] > max) max = mountain[x][y];
			}
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (max == mountain[x][y]) top.push_back({ x, y });
			}
		}

		ans = 0;
		int top_size = top.size();
		for (int i = 0; i < top_size; i++) {
			bfs(top[i].x, top[i].y);
		}

		for (int k = 1; k <= K; k++) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					mountain[x][y] -= k;
					for (int i = 0; i < top_size; i++) {
						bfs(top[i].x, top[i].y);
					}
					mountain[x][y] += k;
				}
			}
		}

		top.clear();

		cout << "#" << t << " " << ans << endl;
	}

	getchar();
	getchar();

	return 0;
}