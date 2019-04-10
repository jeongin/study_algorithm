#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct dir_info {
	int dir[4]; // ºÏ µ¿ ³² ¼­
};

struct xy {
	int x, y;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int N, M;
int board[8][8];
vector<dir_info> cctv[5];
vector<xy> v;
int ans = 0x77777777;

void init() {
	cin >> N >> M;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> board[x][y];
			if (board[x][y] > 0 && board[x][y] < 6) v.push_back({ x,y });
		}
	}

	cctv[0].push_back({ 1, 0, 0, 0 });
	cctv[0].push_back({ 0, 1, 0, 0 });
	cctv[0].push_back({ 0, 0, 1, 0 });
	cctv[0].push_back({ 0, 0, 0, 1 });
	cctv[1].push_back({ 1, 0, 1, 0 });
	cctv[1].push_back({ 0, 1, 0, 1 });
	cctv[2].push_back({ 1, 1, 0, 0 });
	cctv[2].push_back({ 0, 1, 1, 0 });
	cctv[2].push_back({ 0, 0, 1, 1 });
	cctv[2].push_back({ 1, 0, 0, 1 });
	cctv[3].push_back({ 1, 1, 1, 0 });
	cctv[3].push_back({ 0, 1, 1, 1 });
	cctv[3].push_back({ 1, 0, 1, 1 });
	cctv[3].push_back({ 1, 1, 0, 1 });
	cctv[4].push_back({ 1, 1, 1, 1 });
}

void draw(int x, int y, dir_info d) {
	for (int i = 0; i < 4; i++) {
		if (d.dir[i] == 0) continue;

		int nx = x + dx[i], ny = y + dy[i];
		while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6) {
			if (board[nx][ny] == 0) board[nx][ny] = 7;
			nx += dx[i];
			ny += dy[i];
		}
	}
}

void copy_board(int a[][8], int b[][8]) {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			b[x][y] = a[x][y];
		}
	}
}

void dfs(int idx) {
	if (idx == v.size()) {
		int cnt = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (board[x][y] == 0) cnt++;
			}
		}
		if (ans > cnt) ans = cnt;
		return;
	}

	int tmp[8][8];
	int x = v[idx].x, y = v[idx].y;
	int type = board[x][y];
	int n = cctv[type - 1].size();
	copy_board(board, tmp);
	for (int i = 0; i < n; i++) {
		copy_board(tmp, board);
		draw(x, y, cctv[type - 1][i]);
		dfs(idx + 1);
	}
}

int main() {
	// baekjoon 15683

	init();
	dfs(0);

	cout << ans << endl;

	return 0;
}