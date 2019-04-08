#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pii {
	int x, y;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1 ,0 };
int H, W;
int board[8][8];
vector<pii> safe;
vector<pii> virus;
int ans;

void bfs() {
	queue<pii> q;
	int v_size = virus.size();
	for (int i = 0; i < v_size; i++) {
		q.push({ virus[i].x, virus[i].y });
	}

	int tmp[8][8];
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			tmp[x][y] = board[x][y];
		}
	}

	int x, y;
	while (!q.empty()) {
		x = q.front().x, y = q.front().y; q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i], ny = y + dy[i];

			if (nx >= 0 && nx < H && ny >= 0 && ny < W && tmp[nx][ny] == 0) {
				tmp[nx][ny] = 2;
				q.push({ nx,ny });
			}
		}
	}

	int cnt = 0;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			if (tmp[x][y] == 0) cnt++;
		}
	}
	if (ans < cnt) ans = cnt;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		bfs();
		return;
	}

	int safe_size = safe.size();
	for (int i = idx + 1; i < safe_size; i++) {
		board[safe[i].x][safe[i].y] = 1;
		dfs(i, cnt + 1);
		board[safe[i].x][safe[i].y] = 0;
	}
}

/*
1. 벽 3개 세우기 (dfs)
2. 바이러스 퍼트리기 (bfs)
3. 안전영역 세리기
*/
int main() {
	// baekjoon 14502

	cin >> H >> W;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> board[x][y];
			if (board[x][y] == 2) virus.push_back({ x,y });
			else if (board[x][y] == 0) safe.push_back({ x,y });
		}
	}

	int safe_size = safe.size();
	for (int i = 0; i < safe_size; i++) {
		board[safe[i].x][safe[i].y] = 1;
		dfs(i, 1);
		board[safe[i].x][safe[i].y] = 0;
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}