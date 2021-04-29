#include <iostream>
using namespace std;

typedef struct fish {
	int dir = 0;
	int x = 0;
	int y = 0;
	bool alive = true;
}fish;

int ans = 0;
int fishnum[4][4][16];
fish fishinfo[17];
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void fishgo(int sy, int sx, int cnt) {
	//0부터 순서대로 ↑, ↖, ←, ↙, ↓, ↘, →, ↗
	for (int i = 1; i <= 16; i++) {
		for (int k = fishinfo[i].dir; k < fishinfo[i].dir + 8; k++) {
			int temp = k;
			if (temp >= 8) temp -= 8;
			int ny = fishinfo[i].y + dy[temp];
			int nx = fishinfo[i].x + dx[temp];

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) continue;

			fishinfo[fishnum[ny][nx][cnt]].x = fishinfo[i].x;
			fishinfo[fishnum[ny][nx][cnt]].y = fishinfo[i].y;

			int ch = fishnum[ny][nx][cnt];
			fishnum[ny][nx][cnt] = fishnum[fishinfo[i].y][fishinfo[i].x][cnt-1];
			fishnum[fishinfo[i].y][fishinfo[i].x][cnt] = ch;

			fishinfo[i].y = ny;
			fishinfo[i].x = nx;
			fishinfo[i].dir = temp;
			break;
		}
	}
}

int cc() {
	int ans = 0;
	for (int i = 1; i <= 16; i++) {
		if (fishinfo[i].alive == false) ans += i;
	}
	return ans;
}

void go(int sy, int sx, int sd) {
	for (int i = 1; i < 4; i++) {
		int nsy = sy + i * dy[sd];
		int nsx = sx + i * dx[sd];

		if (nsy < 0 || nsy >= 4 || nsx < 0 || nsx >= 4) {
			int c = cc();
			if (ans < c) ans = c;
			break;
		}

		if (fishinfo[fishnum[nsy][nsx]].alive == false) continue;

		fishinfo[fishnum[nsy][nsx]].alive = false;
		go(nsy, nsx, fishinfo[fishnum[nsy][nsx]].dir);
		fishinfo[fishnum[nsy][nsx]].alive = true;
	}
}

void insertData() {
	int dir;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			cin >> fishnum[i][k][0] >> dir;
			fishinfo[fishnum[i][k][0]].y = i;
			fishinfo[fishnum[i][k][0]].x = k;
			fishinfo[fishnum[i][k][0]].dir = dir - 1;
		}
	}
}

int main() {
	insertData();
	fishinfo[fishnum[0][0][0]].alive = false;
	go(0, 0, fishinfo[fishnum[0][0][0]].dir);
	cout << ans;
}