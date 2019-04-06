#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int H, W, D;
int bow[15];
vector<int> enemy[15];
vector<int> tmp_e[15];
int check[15];
int ans;
int result;

/*
1. 궁수 배치 (nC3) // N-1 행 (dfs)
2. 각 궁수가 가장 가까운 적 공격
3. 적 이동
4. 적 남아있는지 확인
*/

// 거리 계산
int cal_dist(int x1, int y1, int x2, int y2) {
	int ans = 0;
	if (x1 > x2) ans += (x1 - x2);
	else ans += (x2 - x1);

	if (y1 > y2) ans += (y1 - y2);
	else ans += (y2 - y1);

	return ans;
}

void find_enemy()
{
	/*printf("=========================\n");
	for (int i = 0; i < W; i++) {
		if (tmp_e[i].empty()) continue;
		printf("[enemy(%d)]: %d\n", i, tmp_e[i].back());
	}*/

	//printf("[bow]: ");
	for (int i = 0; i < W; i++) {
		if (bow[i] == 0) continue;

		//printf("%d ", i);

		int min_dist = 100;
		int idx, dist;
		for (int y = 0; y < W; y++) {
			if (tmp_e[y].empty()) continue;

			dist = H - tmp_e[y].back();
			dist += (i > y) ? i - y : y - i;
			if (dist < min_dist) {
				min_dist = dist;
				idx = y;
			}
		}

		if (min_dist <= D) check[idx] = 1;
	}
}

void attack() {
	for (int i = 0; i < W; i++) {
		if (check[i] == 0) continue;

		ans++;
		tmp_e[i].pop_back();
	}
}

void dfs(int y, int n)
{
	if (n == 3)
	{
		ans = 0;
		for (int i = 0; i < W; i++) {
			int n = enemy[i].size();
			for (int j = 0; j < n; j++) {
				tmp_e[i].push_back(enemy[i][j]);
			}
		}

		while (1) {
			for (int i = 0; i < W; i++) {
				check[i] = 0;
			}
			find_enemy();
			attack();

			for (int i = 0; i < W; i++) {
				if (tmp_e[i].empty()) continue;

				int n = tmp_e[i].size();
				for (int j = 0; j < n; j++) tmp_e[i][j]++;
				if (tmp_e[i][n - 1] == H) tmp_e[i].pop_back();
			}

			int finish = 0;
			for (int i = 0; i < W; i++) {
				finish += tmp_e[i].size();
			}
			if (finish == 0) break;
		}

		if (result < ans) result = ans;

		return;
	}

	for (int i = y + 1; i < W; i++) {
		if (bow[i] == 0) {
			bow[i] = 1;
			dfs(i, n + 1);
			bow[i] = 0;
		}
	}
}

int main() {
	// baekjoon 17135

	scanf("%d %d %d", &H, &W, &D);

	int tmp;
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			scanf("%d", &tmp);
			if (tmp == 1) enemy[w].push_back(h);
		}
	}

	for (int i = 0; i < W; i++) {
		bow[i] = 1;
		dfs(i, 1);
		bow[i] = 0;
	}

	printf("%d\n", result);

	getchar();
	getchar();

	return 0;
}