#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct pos {
	int x;
	int y;
	int d;

	pos(int a, int b, int c) {
		x = a;
		y = b;
		d = c;
	}

	bool operator<(const pos& b) const {
		return d > b.d;
	}
};

int n, m;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<vector<int>> map;
vector<vector<int>> dist;
priority_queue<pos> q;

void insertData() {
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		vector<int> element(n);
		map.push_back(element);
		dist.push_back(element);
		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
			dist[i][j] = 2147000000;
		}
	}

}

void BFS() {
	q.push(pos(0, 0, 0));
	dist[0][0] = 0;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int d = q.top().d;
		q.pop();

		if (x == -1 && y == m - 1) return;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			int ds = dist[x][y] + map[nx][ny];
			if (ds < dist[nx][ny]) {
				dist[nx][ny] = ds;
				q.push(pos(nx, ny, ds));
			}

		}

	}
}



int main() {
	insertData();
	BFS();
	printf("%d", dist[n - 1][m - 1]);

}