#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char a[100][100];
int check[100][100];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int sx = -1, sy = -1, gx, gy;

void insertData() {
	scanf("%d %d", &m, &n);
	char c;
	scanf("%1c", &c);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1c", &a[i][k]);
			if (a[i][k] == 'C') {
				if (sx == -1) {
					sy = i; sx = k;
				}
				else {
					gy = i; gx = k;
				}
			}
		}
		scanf("%1c", &c);
	}
}

void dfs() {
	queue<pair<int, int>> q;
	check[sy][sx] = 1;
	q.push(make_pair(sy, sx));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == gy && x == gx) return;

		for (int i = 0; i < 4; i++) {
			int tmx = x;
			int tmy = y;
			while (1) {
				int nx = tmx + dx[i];
				int ny = tmy + dy[i];
				if (0 > nx || nx >= m || 0 > ny || ny >= n) break;
				if (a[ny][nx] == '*') break;
				if (check[ny][nx] != 0) {
					tmx = nx;
					tmy = ny;
					continue;
				}
				check[ny][nx] = check[y][x] + 1;
				q.push(make_pair(ny, nx));
				tmx = nx;
				tmy = ny;
			}
		}
	}
}
int main() {
	insertData();
	dfs();
	printf("%d", check[gy][gx]-2);
}