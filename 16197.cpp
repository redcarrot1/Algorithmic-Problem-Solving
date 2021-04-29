#include <iostream>
#include <string>
using namespace std;

int n, m;
int map[20][20];
int op[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1,0} }; //y, x
int x_1 = -1, y_1 = -1, x_2 = -1, y_2 = -1;
int ans = 12;

bool checkout(int y, int x) { //나가면 true, 안나가면 false
	if (0 > y || y >= n || 0 > x || x >= m) return true;
	return false;
}

void go(int y1, int x1, int y2, int x2, int cnt) {
	if (cnt >= 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int cy1 = y1 + op[i][0];
		int cx1 = x1 + op[i][1];
		int cy2 = y2 + op[i][0];
		int cx2 = x2 + op[i][1];

		if (checkout(cy1, cx1) != checkout(cy2, cx2)) {
			if (ans > cnt + 1) ans = cnt + 1;
			continue;
		}
		if (checkout(cy1, cx1) && checkout(cy2, cx2)) continue;

		if (map[cy1][cx1] == -1) {
			cy1 = y1;
			cx1 = x1;
		}
		if (map[cy2][cx2] == -1) {
			cy2 = y2;
			cx2 = x2;
		}

		go(cy1, cx1, cy2, cx2, cnt + 1);
	}
}

void insertData() {
	scanf("%d %d", &n, &m); //세로 가로
	char c;

	scanf("%1c", &c);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1c", &c);
			if (c == '.') map[i][k] = 0;
			else if (c == '#') map[i][k] = -1;
			else if (c == 'o') {
				if (x_1 == -1) {
					y_1 = i;
					x_1 = k;
				}
				else {
					y_2 = i;
					x_2 = k;
				}
				map[i][k] = 1;
			}
		}
		scanf("%1c", &c);
	}
}
int main() {
	insertData();
	go(y_1, x_1, y_2, x_2, 0);
	if (ans == 12) printf("-1");
	else printf("%d", ans);
}