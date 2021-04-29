#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int h, w, l;
int a[201][201];
int dy[] = { 0, 0, 1, -1, -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[] = { 1, -1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2 };
int cost[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
int check[201][201][31]; //세로 가로 횟수
int main() {
	cin >> l >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cin >> a[i][k];
		}
	}
	memset(check, -1, sizeof(check));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	check[0][0][0] = 0;

	while (!q.empty()) {
		int x, y, t;
		tie(y, x, t) = q.front();
		q.pop();
		if (x == w - 1 && y == h - 1) break;
		for (int i = 0; i < 12; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nt = t + cost[i];
			if (0 > ny || ny >= h || 0 > nx || nx >= w) continue;
			if (a[ny][nx] == 1) continue;
			if (nt <= l) {
				if (check[ny][nx][nt] == -1) {
					q.push(make_tuple(ny, nx, nt));
					check[ny][nx][nt] = check[y][x][t] + 1;
				}
			}

		}
	}
	int ans = -1;
	for (int i = 0; i <= l; i++) {
		if (check[h - 1][w - 1][i] ==-1) continue;
		if (ans==-1 || ans > check[h - 1][w - 1][i]) ans = check[h - 1][w - 1][i];
	}
	cout << ans;
}