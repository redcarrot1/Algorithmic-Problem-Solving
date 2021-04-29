#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int a[8][8];
bool check[8][8][9];
int dx[] = { 0,0,1,-1,1,-1,1,-1,0 };
int dy[] = { 1,-1,0,0,1,1,-1,-1,0 };

int main() {
	char c;
	for (int i = 0; i < 8; i++) {
		for (int k = 0; k < 8; k++) {
			scanf("%1c", &c);
			if (c == '.') a[i][k] = 0;
			else a[i][k] = 1;
		}
		scanf("%1c", &c);
	}

	queue<tuple<int, int, int>> q;

	q.push(make_tuple(7, 0, 0));
	check[7][0][0] = true;

	bool ans = false;
	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front(); q.pop();
		if (x == 0 && y == 7) ans = true;
		for (int k = 0; k < 9; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			int nt = min(t + 1, 8);
			if (0 <= nx && nx < 8 && 0 <= ny && ny < 8) {
				if (nx - t >= 0 && a[nx - t][ny] == 1) continue;
				if (nx - t - 1 >= 0 && a[nx - t - 1][ny] == 1) continue;
				if (check[nx][ny][nt] == false) {
					check[nx][ny][nt] = true;
					q.push(make_tuple(nx, ny, nt));
				}
			}
		}
	}
	cout << (ans ? 1 : 0) << '\n';
}