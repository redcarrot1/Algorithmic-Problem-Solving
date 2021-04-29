#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[1000][1000];
int check[1000][1000];
vector<pair<int, int>> v;
int n, m; //세로길이n, 가로길이m

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void insertData() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin>>map[i][k];
			if (map[i][k] == 1) v.push_back(make_pair(i, k));
			else if (map[i][k] == -1) check[i][k] = -1;
		}
	}
}


void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		check[v[i].first][v[i].second]=1;
		q.push(make_pair(v[i].first, v[i].second));
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cy = y + dy[i];
			int cx = x + dx[i];
			if (0 <= cx && cx < m && 0 <= cy && cy < n) {
				if (map[cy][cx] == 0 && check[cy][cx] == 0) {
					check[cy][cx] = check[y][x] + 1;
					q.push(make_pair(cy, cx));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	insertData();
	bfs();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (check[i][k] == 0) { cout << "-1"; return 0; }
			if (ans < check[i][k]) ans = check[i][k];
		}
	}
	cout << ans-1;

}