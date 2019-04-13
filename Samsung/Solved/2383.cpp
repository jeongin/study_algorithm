#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <math.h>

using namespace std;

struct stair {
	int x, y, height;
	deque<int> now;
};

struct people {
	int x, y;
	int dist[2] = { 0, };
};

int N;
stair s[2];
vector<people> p;
int what_stair[10];
int ans;

void simulation() {
	int p_size = p.size();

	int t = 0;
	int check[10] = { 0, };
	int type, height;
	int s_size;
	while (1) {
		for (int i = 0; i < 2; i++) {
			s_size = s[i].now.size();
			if (s_size == 0) continue;

			for (int j = 0; j < s_size; j++) {
				if (s[i].now[j] == 0) {
					s[i].now.pop_front();
					j--;
					s_size--;
				}
			}

			for (int j = 0; (j < s_size && j < 3); j++) {
				s[i].now[j]--;
			}

			int aaa = 0;
		}

		int finish = 1;
		for (int i = 0; i < p_size; i++) {
			if (check[i] == 0) finish = 0;
		}

		if (finish == 1 && s[0].now.size() == 0 && s[1].now.size() == 0) {
			if (t < ans) ans = t;
			break;
		}

		for (int i = 0; i < p_size; i++) {
			type = what_stair[i];
			if (check[i] == 0 && p[i].dist[type] <= t) {
				check[i] = 1;
				height = s[type].height;
				s[type].now.push_back(height);
			}
		}

		t++;
	}
}

void select_stair(int idx, int s_num) {
	if (idx == p.size()) {
		simulation();
		return;
	}

	what_stair[idx] = s_num;

	for (int i = 0; i < 2; i++) {
		select_stair(idx + 1, i);
	}
}

int main(int argc, char** argv) {
	// samsung 2383

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		p.clear();
		s[0].now.clear();
		s[1].now.clear();
		for (int i = 0; i < 10; i++) {
			what_stair[i] = -1;
		}
		ans = 0x7fffffff;

		cin >> N;
		int tmp;
		int idx = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				cin >> tmp;
				people tmp_p;
				tmp_p.x = x, tmp_p.y = y;
				if (tmp == 1) p.push_back(tmp_p);
				else if (tmp > 1) s[idx].x = x, s[idx].y = y, s[idx++].height = tmp;
			}
		}

		int p_size = p.size();
		for (int i = 0; i < p_size; i++) {
			for (int j = 0; j < 2; j++) {
				p[i].dist[j] = abs(p[i].x - s[j].x) + abs(p[i].y - s[j].y);
			}
		}

		for (int i = 0; i < 2; i++) {
			select_stair(0, i);
		}

		cout << "#" << t << " " << ans << endl;
	}

	getchar();
	getchar();

	return 0;
}