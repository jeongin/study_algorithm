#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct nation {
	int people;
	int block[4] = { 0,0,0,0 }; // right, bottom, left, top
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, L, R;
int check[50][50];
nation board[50][50];
vector<pair<int, int>> v;
int ans;

/*
1. 국경선 열릴 수 있는지 확인
2. 국경선 열려있는 nation의 좌표(x,y)를 q에 추가하기
3. q에 있는 nation들의 인구 모두 합쳐서 각 nation의 인구수 변경하기
*/

int check_block() {
	int nx, ny;
	int a, b, c;
	int check = 1;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			a = board[x][y].people;
			for (int k = 0; k < 4; k++) {
				c = 0;
				nx = x + dx[k];
				ny = y + dy[k];
				if (nx < 0 || nx > N - 1 || ny <0 || ny > N - 1) {
					continue;
				}
				b = board[nx][ny].people;
				c = (a > b) ? a - b : b - a;
				if (c >= L && c <= R) {
					check = 0;
					board[x][y].block[k] = 1;
					board[nx][ny].block[(k + 2) % 4] = 1;
				}
			}
		}
	}

	return check;
}

void united(int x, int y) {
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		if (board[x][y].block[i] == 1) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
			if (check[nx][ny] == 1) continue;
			check[nx][ny] = 1;
			v.push_back(make_pair(nx, ny));
			united(nx, ny);
		}
	}
}

void people_move() {
	int sum = 0;
	int v_size = v.size();
	for (int i = 0; i < v_size; i++) {
		sum += board[v[i].first][v[i].second].people;
	}

	int next_people = sum / v_size;

	while (v_size) {
		board[v[v_size - 1].first][v[v_size - 1].second].people = next_people;
		v.pop_back();
		v_size--;
	}
}

int main() {
	// baekjoon 16234

	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j].people);
		}
	}

	int finish = 0;
	while (!finish) {
		finish = check_block();

		if (finish == 0)
			ans++;

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (check[x][y] == 0) {
					check[x][y] = 1;
					v.push_back(make_pair(x, y));
					united(x, y);
					people_move();
				}
			}
		}

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				check[x][y] = 0;
				board[x][y].block[0] = 0;
				board[x][y].block[1] = 0;
				board[x][y].block[2] = 0;
				board[x][y].block[3] = 0;
			}
		}
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}