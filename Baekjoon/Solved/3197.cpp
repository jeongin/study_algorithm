#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct xy {
	int x, y;
};

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int H, W;
char lake[1500][1500];
queue<xy> swan, nswan;
queue<xy> water, nwater;
xy swan_xy;
int wvisit[1500][1500];
int svisit[1500][1500];

int main() {
	// baekjoon 3197

	cin >> H >> W;
	string tmp;
	for (int x = 0; x < H; x++) {
		cin >> tmp;
		for (int y = 0; y < W; y++) {
			lake[x][y] = tmp[y];
			if (tmp[y] == 'L') {
				swan.push({ x,y });
				lake[x][y] = '.';
				water.push({ x,y });
			}
			if (tmp[y] == '.') {
				water.push({ x,y });
				wvisit[x][y] = 1;
			}
		}
	}

	swan_xy.x = swan.front().x;
	swan_xy.y = swan.front().y;
	swan.pop();

	svisit[swan.front().x][swan.front().y] = 1;

	int ans;
	for (ans = 0; !svisit[swan_xy.x][swan_xy.y]; ans++) {
		while (!water.empty()) {
			nwater.push(water.front());
			water.pop();
		}
		while (!swan.empty()) {
			nswan.push(swan.front());
			swan.pop();
		}

		while (!nwater.empty()) {
			int x = nwater.front().x, y = nwater.front().y;
			nwater.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W || wvisit[nx][ny]) continue;

				lake[nx][ny] = '.';
				wvisit[nx][ny] = 1;
				water.push({ nx,ny });
			}
		}

		while (!nswan.empty()) {
			int x = nswan.front().x, y = nswan.front().y;
			nswan.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W || svisit[nx][ny]) continue;

				svisit[nx][ny] = 1;
				if (lake[nx][ny] == '.') nswan.push({ nx,ny });
				else if (lake[nx][ny] == 'X') swan.push({ nx,ny });
			}
		}

		/*printf("=======================\n");
		for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
		printf("%c", lake[x][y]);
		}
		printf("\n");
		}*/
	}

	cout << ans << endl;

	getchar();
	getchar();

	return 0;
}