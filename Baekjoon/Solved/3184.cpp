#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int R, C;
char board[250][250];
int visit[250][250];
int e_visit[250][250];
stack<pair<int, int>> s;
int o = 0, v = 0;

void bfs(int x, int y, int type) {
	if (board[x][y] == '#')
		return;

	if (type == 0 && visit[x][y])
		return;
	else if (type == 1 && e_visit[x][y])
		return;

	if (type == 0) {
		visit[x][y] = 1;
		s.push(make_pair(x, y));
	}
	else if (type == 1)
	{
		e_visit[x][y] = 1;
		if (o > v && board[x][y] == 'v')
			board[x][y] = '.';
		else if (o <= v && board[x][y] == 'o')
			board[x][y] = '.';
	}

	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx < 0 || nx > R - 1 || ny <0 || ny > C - 1) {
			continue;
		}

		bfs(nx, ny, type);
	}
}

int main() {
	// baekjoon 3184

	scanf("%d %d", &R, &C);
	string tmp;
	for (int i = 0; i < R; i++) {
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			board[i][j] = tmp[j];
		}
	}

	pair<int, int> xy;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			bfs(i, j, 0);

			while (!s.empty()) {
				xy = s.top(); s.pop();
				if (board[xy.first][xy.second] == 'o') {
					o++;
				}
				else if (board[xy.first][xy.second] == 'v') {
					v++;
				}
			}

			bfs(i, j, 1);
			o = 0, v = 0;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'o')
				o++;
			else if (board[i][j] == 'v')
				v++;
		}
	}

	printf("%d %d\n", o, v);

	getchar();
	getchar();

	return 0;
}