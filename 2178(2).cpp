#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;

void bfs(int x, int y) {
	d[y][x] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < m && 0 <= ny && ny < n) {
				if (a[ny][nx] == 1 && d[ny][nx] == 0) {
					d[ny][nx] = d[y][x]+1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void insertData() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	insertData();
	bfs(0, 0);
	printf("%d", d[n - 1][m - 1]);
}