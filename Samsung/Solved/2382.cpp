#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct group {
	int num, dir;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N, M, K;
vector<group> v[100][100];
vector<group> nv[100][100];

int main(int argc, char** argv) {
	// samsung 2382

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		int x_in, y_in, n_in, d_in;
		for (int k = 0; k < K; k++) {
			cin >> x_in >> y_in >> n_in >> d_in;
			if (d_in == 1) d_in = 0;
			else if (d_in == 2) d_in = 2;
			else if (d_in == 3) d_in = 1;
			else d_in = 3;

			v[x_in][y_in].push_back({ n_in, d_in });
		}

		int nx, ny, nn, nd, v_size;
		int max_num;
		for (int m = 0; m < M; m++) {
			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					// 미생물 이동
					if (v[x][y].size() == 0) continue;

					nn = v[x][y][0].num; nd = v[x][y][0].dir;
					nx = x + dx[nd], ny = y + dy[nd];
					if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
						nn /= 2;
						nd = (nd + 2) % 4;
					}
					nv[nx][ny].push_back({ nn, nd });
					v[x][y].clear();
				}
			}

			for (int x = 0; x < N; x++) {
				for (int y = 0; y < N; y++) {
					// 미생물 합치기
					v_size = nv[x][y].size();
					if (v_size == 0) continue;

					max_num = 0;
					nn = 0;
					for (int i = 0; i < v_size; i++) {
						group g = nv[x][y][i];
						nn += g.num;
						if (g.num > max_num) {
							max_num = g.num;
							nd = g.dir;
						}
					}
					nv[x][y].clear();
					v[x][y].push_back({ nn, nd });
				}
			}

			/*printf("===============================\n");
			for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
			if (v[x][y].size() == 0) printf("%4d ", 0);
			else printf("%4d ", v[x][y][0].num);
			}
			cout << endl;
			}*/
		}

		int cnt = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (v[x][y].size() == 0) continue;
				cnt += v[x][y][0].num;
				v[x][y].clear();
			}
		}

		cout << "#" << t << " " << cnt << endl;
	}

	getchar();
	getchar();

	return 0;
}