#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct xy {
	int x, y;
};

int N, M;
vector<xy> house;
vector<xy> chicken;
int check[13];
int ans = 0x7fffffff;

void dfs(int idx, int cnt) {
	if (cnt == M) {
		int sum_dist = 0;
		for (int i = 0; i < house.size(); i++) {
			int min_dist = 0x7fffffff;
			for (int j = 0; j < chicken.size(); j++) {
				if (check[j] == 1) {
					int dist = 0;
					if (house[i].x > chicken[j].x) dist += house[i].x - chicken[j].x;
					else dist += chicken[j].x - house[i].x;
					if (house[i].y > chicken[j].y) dist += house[i].y - chicken[j].y;
					else dist += chicken[j].y - house[i].y;

					if (min_dist > dist) min_dist = dist;
				}
			}
			sum_dist += min_dist;
		}
		if (sum_dist < ans) ans = sum_dist;
		return;
	}

	for (int i = idx + 1; i < chicken.size(); i++) {
		check[i] = 1;
		dfs(i, cnt + 1);
		check[i] = 0;
	}
}

int main() {
	// baekjoon 15686

	cin >> N >> M;
	int tmp;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> tmp;
			if (tmp == 1) house.push_back({ x,y });
			if (tmp == 2) chicken.push_back({ x,y });
		}
	}

	for (int i = 0; i < chicken.size(); i++) {
		check[i] = 1;
		dfs(i, 1);
		check[i] = 0;
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}