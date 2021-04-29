#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int h, w;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int p1x = -1, p1y = -1, p2x, p2y;
char map[102][102];

void seta(int a[102][102]) {
	for (int i = 0; i <= h + 1; i++) {
		for (int j = 0; j <= w + 1; j++) {
			a[i][j] = -1;
		}
	}
}
void bfs(int a[102][102], int py, int px) {
	seta(a);
	deque<pair<int, int>> q;
	q.push_back(make_pair(py, px));
	a[py][px] = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= nx && nx <= w + 1 && 0 <= ny && ny <= h + 1) {
				if (a[ny][nx] != -1) continue;
				if (map[ny][nx] == '*') continue;
				if (map[ny][nx] == '#') {
					a[ny][nx] = a[y][x] + 1;
					q.push_back(make_pair(ny, nx));
				}
				else {
					a[ny][nx] = a[y][x];
					q.push_front(make_pair(ny, nx));
				}
			}
		}
	}

}

void setMap() {
	char c;
	scanf("%1c", &c); //엔터먹는용
	for (int k = 1; k <= h; k++) {
		map[k][0] = '.';
		for (int i = 1; i <= w; i++) {
			scanf("%1c", &c);
			if (c == '$') {
				if (p1x == -1) {
					p1y = k;
					p1x = i;
				}
				else {
					p2y = k;
					p2x = i;
				}
			}
			map[k][i] = c;
		}
		map[k][w + 1] = '.';
		scanf("%1c", &c); //엔터먹는용
	}

	for (int i = 0; i < w + 2; i++) {
		map[0][i] = '.';
		map[h + 1][i] = '.';
	}
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &h, &w);
		//빈 공간은 '.', 지나갈 수 없는 벽은 '*', 문은 '#', 죄수의 위치는 '$'
		p1x = -1;
		setMap();

		int a1[102][102]{};
		int a2[102][102]{};
		int a3[102][102]{};
		bfs(a1, 0, 0);
		bfs(a2, p1y, p1x);
		bfs(a3, p2y, p2x);

		int min = h * w;
		int temp;
		for (int k = 0; k <= h + 1; k++) {
			for (int i = 0; i <= w + 1; i++) {
				if (map[k][i] == '*') continue;
				if (a1[k][i] == -1 || a2[k][i] == -1 || a3[k][i] == -1) continue;
				temp = a1[k][i] + a2[k][i] + a3[k][i];
				if (map[k][i] == '#') temp -= 2;

				if (temp < min) min = temp;
			}
		}
		printf("%d\n", min);
	}
}