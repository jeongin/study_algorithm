#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <math.h>
#define L -1
#define R 1

using namespace std;

struct rotation {
	int num;
	int rotate_d;
};
deque<int> wheel[4];
int K;
deque<rotation> info;

void rotate(int num, int rotate_d) {
	if (rotate_d == L) {
		wheel[num].push_back(wheel[num][0]);
		wheel[num].pop_front();
	}
	else if (rotate_d == R) {
		wheel[num].push_front(wheel[num][7]);
		wheel[num].pop_back();
	}
}

void rotate_check(int num, int rotate_d, int d) {
	if (d == 0 && num - 1 >= 0 && wheel[num][6] != wheel[num - 1][2]) { // ¿ÞÂÊ
		rotate_check(num - 1, rotate_d * -1, d);
	}
	if (d == 1 && num + 1 < 4 && wheel[num][2] != wheel[num + 1][6]) { // ¿À¸¥ÂÊ
		rotate_check(num + 1, rotate_d * -1, d);
	}

	if (num == info[0].num) return;

	rotate(num, rotate_d);
}

int main() {
	// baekjoon 14891

	string tmp;
	for (int i = 0; i < 4; i++) {
		cin >> tmp;
		for (int j = 0; j < 8; j++) {
			if (tmp[j] == '0') wheel[i].push_back(0);
			else if (tmp[j] == '1') wheel[i].push_back(1);
		}
	}

	cin >> K;
	int tmp_n, tmp_d;
	for (int i = 0; i < K; i++) {
		cin >> tmp_n >> tmp_d;
		info.push_back({ tmp_n - 1, tmp_d });
	}

	while (!info.empty()) {
		rotate_check(info[0].num, info[0].rotate_d, 0);
		rotate_check(info[0].num, info[0].rotate_d, 1);
		rotate(info[0].num, info[0].rotate_d);
		info.pop_front();
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (wheel[i][0] == 1) ans += pow(2, i);
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}