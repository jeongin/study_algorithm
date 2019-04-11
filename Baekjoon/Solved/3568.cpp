#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	// baekjoon 3568

	string pre_input;
	cin >> pre_input;

	int common_s = 0, common_e = 0;
	for (int i = 0; i < pre_input.length(); i++) {
		if (common_s == 0 && (pre_input[i] == '[' || pre_input[i] == '*' || pre_input[i] == '&')) common_s = i;
	}
	common_e = pre_input.length() - 1;

	vector<char> var[120];

	string input = " ";
	int cnt = 0;
	while (input[input.length() - 1] != ';') {
		cin >> input;
		for (int i = 0; i < input.length() - 1; i++) {
			var[cnt].push_back(input[i]);
		}
		cnt++;
	}

	for (int i = 0; i < cnt; i++) {
		cout << pre_input;
		int check = 0;
		int v_size = var[i].size();
		for (int j = 0; j < v_size; j++) {
			char now = var[i].back();
			if (now != '*' && now != '&' && now != '[' && now != ']' && check == 0) {
				cout << " ";
				check = 1;
			}

			if (check == 1) {
				for (int k = 0; k < v_size - j; k++) {
					cout << var[i][k];
				}
				break;
			}

			var[i].pop_back();
			if (now == ']') {
				cout << "[]";
				var[i].pop_back();
				j++;
			}
			else cout << now;
		}
		cout << ";" << endl;
	}

	getchar();
	getchar();

	return 0;
}