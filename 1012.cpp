#include <iostream>
#include <queue>
using namespace std;

int h, w;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0,0 };

int a[50][50];
bool check[50][50];

void bfs(int sy, int sx) {

	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 > ny || ny >= h || 0 > nx || nx >= w) continue;
			if (check[ny][nx] != 0 || a[ny][nx] == 0) continue;
			q.push(make_pair(ny, nx));
			check[ny][nx] = true;
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> w >> h >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			a[y][x] = 1;
		}

		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				if (check[i][k] == 0 && a[i][k] == 1) {
					bfs(i, k);
					ans += 1;
				}
			}
		}

		cout << ans << '\n';

		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				a[i][k] = 0;
				check[i][k] = 0;
			}
		}
	}

	
}