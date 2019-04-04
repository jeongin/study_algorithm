#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int T, N;
queue<pair<char, char>> q;

char cube[6][9]; // 위 아래 앞 뒤 왼 오

void make_cube() { // w y r o g b
	for (int side = 0; side < 6; side++) {
		for (int i = 0; i < 9; i++) {
			if (side == 0) cube[side][i] = 'w';
			else if (side == 1)cube[side][i] = 'y';
			else if (side == 2)cube[side][i] = 'r';
			else if (side == 3)cube[side][i] = 'o';
			else if (side == 4)cube[side][i] = 'g';
			else if (side == 5)cube[side][i] = 'b';
		}
	}
}

void change_cube(char side, char d) {
	char tmp[12];
	int plus = 0;
	int i_side;
	switch (side) {
	case 'U':
		i_side = 0;
		tmp[0] = cube[2][0];
		tmp[1] = cube[2][1];
		tmp[2] = cube[2][2];
		tmp[3] = cube[5][0];
		tmp[4] = cube[5][1];
		tmp[5] = cube[5][2];
		tmp[6] = cube[3][0];
		tmp[7] = cube[3][1];
		tmp[8] = cube[3][2];
		tmp[9] = cube[4][0];
		tmp[10] = cube[4][1];
		tmp[11] = cube[4][2];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[2][0] = tmp[(3 + plus) % 12];
		cube[2][1] = tmp[(4 + plus) % 12];
		cube[2][2] = tmp[(5 + plus) % 12];
		cube[5][0] = tmp[(6 + plus) % 12];
		cube[5][1] = tmp[(7 + plus) % 12];
		cube[5][2] = tmp[(8 + plus) % 12];
		cube[3][0] = tmp[(9 + plus) % 12];
		cube[3][1] = tmp[(10 + plus) % 12];
		cube[3][2] = tmp[(11 + plus) % 12];
		cube[4][0] = tmp[(0 + plus) % 12];
		cube[4][1] = tmp[(1 + plus) % 12];
		cube[4][2] = tmp[(2 + plus) % 12];

		break;
	case 'D':
		i_side = 1;
		tmp[0] = cube[3][8];
		tmp[1] = cube[3][7];
		tmp[2] = cube[3][6];
		tmp[3] = cube[5][8];
		tmp[4] = cube[5][7];
		tmp[5] = cube[5][6];
		tmp[6] = cube[2][8];
		tmp[7] = cube[2][7];
		tmp[8] = cube[2][6];
		tmp[9] = cube[4][8];
		tmp[10] = cube[4][7];
		tmp[11] = cube[4][6];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[3][8] = tmp[(3 + plus) % 12];
		cube[3][7] = tmp[(4 + plus) % 12];
		cube[3][6] = tmp[(5 + plus) % 12];
		cube[5][8] = tmp[(6 + plus) % 12];
		cube[5][7] = tmp[(7 + plus) % 12];
		cube[5][6] = tmp[(8 + plus) % 12];
		cube[2][8] = tmp[(9 + plus) % 12];
		cube[2][7] = tmp[(10 + plus) % 12];
		cube[2][6] = tmp[(11 + plus) % 12];
		cube[4][8] = tmp[(0 + plus) % 12];
		cube[4][7] = tmp[(1 + plus) % 12];
		cube[4][6] = tmp[(2 + plus) % 12];

		break;
	case 'F':
		i_side = 2;
		tmp[0] = cube[1][0];
		tmp[1] = cube[1][1];
		tmp[2] = cube[1][2];
		tmp[3] = cube[5][6];
		tmp[4] = cube[5][3];
		tmp[5] = cube[5][0];
		tmp[6] = cube[0][8];
		tmp[7] = cube[0][7];
		tmp[8] = cube[0][6];
		tmp[9] = cube[4][2];
		tmp[10] = cube[4][5];
		tmp[11] = cube[4][8];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[1][0] = tmp[(3 + plus) % 12];
		cube[1][1] = tmp[(4 + plus) % 12];
		cube[1][2] = tmp[(5 + plus) % 12];
		cube[5][6] = tmp[(6 + plus) % 12];
		cube[5][3] = tmp[(7 + plus) % 12];
		cube[5][0] = tmp[(8 + plus) % 12];
		cube[0][8] = tmp[(9 + plus) % 12];
		cube[0][7] = tmp[(10 + plus) % 12];
		cube[0][6] = tmp[(11 + plus) % 12];
		cube[4][2] = tmp[(0 + plus) % 12];
		cube[4][5] = tmp[(1 + plus) % 12];
		cube[4][8] = tmp[(2 + plus) % 12];

		break;
	case 'B':
		i_side = 3;
		tmp[0] = cube[1][8];
		tmp[1] = cube[1][7];
		tmp[2] = cube[1][6];
		tmp[3] = cube[4][6];
		tmp[4] = cube[4][3];
		tmp[5] = cube[4][0];
		tmp[6] = cube[0][0];
		tmp[7] = cube[0][1];
		tmp[8] = cube[0][2];
		tmp[9] = cube[5][2];
		tmp[10] = cube[5][5];
		tmp[11] = cube[5][8];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[1][8] = tmp[(3 + plus) % 12];
		cube[1][7] = tmp[(4 + plus) % 12];
		cube[1][6] = tmp[(5 + plus) % 12];
		cube[4][6] = tmp[(6 + plus) % 12];
		cube[4][3] = tmp[(7 + plus) % 12];
		cube[4][0] = tmp[(8 + plus) % 12];
		cube[0][0] = tmp[(9 + plus) % 12];
		cube[0][1] = tmp[(10 + plus) % 12];
		cube[0][2] = tmp[(11 + plus) % 12];
		cube[5][2] = tmp[(0 + plus) % 12];
		cube[5][5] = tmp[(1 + plus) % 12];
		cube[5][8] = tmp[(2 + plus) % 12];

		break;
	case 'L':
		i_side = 4;
		tmp[0] = cube[2][6];
		tmp[1] = cube[2][3];
		tmp[2] = cube[2][0];
		tmp[3] = cube[0][6];
		tmp[4] = cube[0][3];
		tmp[5] = cube[0][0];
		tmp[6] = cube[3][2];
		tmp[7] = cube[3][5];
		tmp[8] = cube[3][8];
		tmp[9] = cube[1][6];
		tmp[10] = cube[1][3];
		tmp[11] = cube[1][0];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[2][6] = tmp[(3 + plus) % 12];
		cube[2][3] = tmp[(4 + plus) % 12];
		cube[2][0] = tmp[(5 + plus) % 12];
		cube[0][6] = tmp[(6 + plus) % 12];
		cube[0][3] = tmp[(7 + plus) % 12];
		cube[0][0] = tmp[(8 + plus) % 12];
		cube[3][2] = tmp[(9 + plus) % 12];
		cube[3][5] = tmp[(10 + plus) % 12];
		cube[3][8] = tmp[(11 + plus) % 12];
		cube[1][6] = tmp[(0 + plus) % 12];
		cube[1][3] = tmp[(1 + plus) % 12];
		cube[1][0] = tmp[(2 + plus) % 12];

		break;
	case 'R':
		i_side = 5;
		tmp[0] = cube[1][2];
		tmp[1] = cube[1][5];
		tmp[2] = cube[1][8];
		tmp[3] = cube[3][6];
		tmp[4] = cube[3][3];
		tmp[5] = cube[3][0];
		tmp[6] = cube[0][2];
		tmp[7] = cube[0][5];
		tmp[8] = cube[0][8];
		tmp[9] = cube[2][2];
		tmp[10] = cube[2][5];
		tmp[11] = cube[2][8];

		if (d == '+') plus = 0;
		if (d == '-') plus = 6;

		cube[1][2] = tmp[(3 + plus) % 12];
		cube[1][5] = tmp[(4 + plus) % 12];
		cube[1][8] = tmp[(5 + plus) % 12];
		cube[3][6] = tmp[(6 + plus) % 12];
		cube[3][3] = tmp[(7 + plus) % 12];
		cube[3][0] = tmp[(8 + plus) % 12];
		cube[0][2] = tmp[(9 + plus) % 12];
		cube[0][5] = tmp[(10 + plus) % 12];
		cube[0][8] = tmp[(11 + plus) % 12];
		cube[2][2] = tmp[(0 + plus) % 12];
		cube[2][5] = tmp[(1 + plus) % 12];
		cube[2][8] = tmp[(2 + plus) % 12];

		break;
	}

	char main_side[9];
	for (int i = 0; i < 9; i++) {
		main_side[i] = cube[i_side][i];
	}

	if (d == '+') {
		cube[i_side][0] = main_side[6];
		cube[i_side][1] = main_side[3];
		cube[i_side][2] = main_side[0];
		cube[i_side][3] = main_side[7];
		cube[i_side][4] = main_side[4];
		cube[i_side][5] = main_side[1];
		cube[i_side][6] = main_side[8];
		cube[i_side][7] = main_side[5];
		cube[i_side][8] = main_side[2];
	}
	else if (d == '-') {
		cube[i_side][0] = main_side[2];
		cube[i_side][1] = main_side[5];
		cube[i_side][2] = main_side[8];
		cube[i_side][3] = main_side[1];
		cube[i_side][4] = main_side[4];
		cube[i_side][5] = main_side[7];
		cube[i_side][6] = main_side[0];
		cube[i_side][7] = main_side[3];
		cube[i_side][8] = main_side[6];
	}
}

int main() {
	// baekjoon 5373

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d", &N);
		string s;
		for (int i = 0; i < N; i++) {
			cin >> s;
			q.push(make_pair(s[0], s[1]));
		}

		make_cube();

		while (!q.empty()) {
			char side = q.front().first;
			char d = q.front().second;
			q.pop();

			change_cube(side, d);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", cube[0][3 * i + j]);
			}
			printf("\n");
		}

	}

	getchar();
	getchar();

	return 0;
}