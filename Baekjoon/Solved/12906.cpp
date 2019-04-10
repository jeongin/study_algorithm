#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct status {
	string stick[3];
	int move_cnt;
};
bool operator<(const status& s1, const status& s2) {
	if (s1.stick[0] == s2.stick[0]) {
		if (s1.stick[1] == s2.stick[1]) {
			return s1.stick[2] < s2.stick[2];
		}
		return s1.stick[1] < s2.stick[1];
	}
	return s1.stick[0] < s2.stick[0];
}

int N;
string stick[3];
queue<status> q;
set<status> visit;
char ABC[3] = { 'A', 'B', 'C' };
int ans;

int check_stick(string s[3]) {
	for (int i = 0; i < 3; i++) {
		int len = s[i].length();
		for (int j = 0; j < len; j++) {
			if (s[i][j] != ABC[i]) return 0;
		}
	}

	return 1;
}

int main() {
	// baekjoon 12906

	for (int i = 0; i < 3; i++) {
		cin >> N;
		if (N == 0) continue;
		cin >> stick[i];
	}

	status fs;
	fs.stick[0] = stick[0], fs.stick[1] = stick[1], fs.stick[2] = stick[2], fs.move_cnt = 0;
	q.push(fs);
	visit.insert(fs);
	string s[3];
	string tmp[3];
	while (!q.empty()) {
		s[0] = q.front().stick[0];
		s[1] = q.front().stick[1];
		s[2] = q.front().stick[2];
		int cnt = q.front().move_cnt;
		q.pop();

		if (check_stick(s) == 1) {
			ans = cnt;
			break;
		}

		status ts;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || s[i].length() == 0) continue;

				tmp[0] = s[0], tmp[1] = s[1], tmp[2] = s[2];
				tmp[j] += tmp[i].back();
				tmp[i].pop_back();

				ts.stick[0] = tmp[0], ts.stick[1] = tmp[1], ts.stick[2] = tmp[2], ts.move_cnt = cnt + 1;
				if (visit.count(ts) == 1) continue;
				q.push(ts);
				visit.insert(ts);

			}
		}
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}