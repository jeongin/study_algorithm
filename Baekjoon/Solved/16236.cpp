#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct boss {
	int x, y, size, eat;
};

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N;
int board[20][20];
int check[20][20];
boss big_boss;
int time;
queue<pair<pair<int, int>, int>> q;
vector<pair<pair<int, int>, int>> next_site;


int fish_dist() {
	int finish = 1;
	q.push(make_pair(make_pair(big_boss.x, big_boss.y), 0));
	check[big_boss.x][big_boss.y] = 1;

	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (check[nx][ny] == 1) continue;

			check[nx][ny] = 1;

			if (board[nx][ny] == 0 || board[nx][ny] == big_boss.size) {
				q.push(make_pair(make_pair(nx, ny), dist + 1));
			}
			else if (board[nx][ny] < big_boss.size) {
				next_site.push_back(make_pair(make_pair(nx, ny), dist + 1));
				/*board[nx][ny] = 0;

				if (big_boss.x > nx) time += big_boss.x - nx;
				else time += nx - big_boss.x;

				if (big_boss.y > ny) time += big_boss.y - ny;
				else time += ny - big_boss.y;

				big_boss.x = nx;
				big_boss.y = ny;
				big_boss.eat++;
				if (big_boss.size == big_boss.eat) {
				big_boss.size++;
				big_boss.eat = 0;
				}*/
				finish = 0;
			}
		}
	}

	return finish;
}

int main() {
	// baekjoon 16236

	scanf("%d", &N);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			scanf("%d", &board[x][y]);
			if (board[x][y] == 9) {
				big_boss.x = x;
				big_boss.y = y;
				big_boss.size = 2;
				big_boss.eat = 0;
				board[x][y] = 0;
			}
		}
	}

	int finish = 0;
	while (finish == 0) {
		//printf("================\n");
		//printf("[x]: %d [y]: %d\n[size]: %d [eat]: %d\n[t]: %d\n", big_boss.x, big_boss.y, big_boss.size, big_boss.eat, time);
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				check[x][y] = 0;
				//printf("%d ", board[x][y]);
			}
			//printf("\n");
		}
		finish = fish_dist();

		if (finish == 1) break;

		int nx, ny;
		int min_dist = 1000000;
		int dist;
		for (int i = next_site.size() - 1; i >= 0; i--) {
			dist = next_site[i].second;

			if (dist < min_dist) {
				min_dist = dist;
				nx = next_site[i].first.first;
				ny = next_site[i].first.second;
			}
			else if (dist == min_dist) {
				if (next_site[i].first.first < nx) {
					nx = next_site[i].first.first;
					ny = next_site[i].first.second;
				}
				else if (next_site[i].first.first == nx && next_site[i].first.second < ny) {
					nx = next_site[i].first.first;
					ny = next_site[i].first.second;
				}
			}
			next_site.pop_back();
		}

		big_boss.x = nx;
		big_boss.y = ny;
		board[nx][ny] = 0;
		big_boss.eat++;
		if (big_boss.eat == big_boss.size) {
			big_boss.size++;
			big_boss.eat = 0;
		}
		time += min_dist;
	}

	printf("%d\n", time);

	getchar();
	getchar();

	return 0;
}