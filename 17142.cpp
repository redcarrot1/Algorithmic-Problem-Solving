#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int a[50][50];
int n, m;
vector<pair<int, int>> canvi;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int bfs() {
	queue<pair<int, int>> q;
	int d[50][50];
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			d[i][k] = -1;
			if (a[i][k] == 3) {
				q.push(make_pair(i, k));
				d[i][k] = 0;
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 > nx || n <= nx || 0 > ny || n <= ny) continue;
			if (d[ny][nx] != -1) continue;
			if (a[ny][nx] == 1) continue;
			q.push(make_pair(ny, nx));
			d[ny][nx] = d[y][x] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] != 1 && d[i][k] == -1) return -1;
			if (ans < d[i][k] && a[i][k]==0) ans = d[i][k];
		}
	}
	return ans;
}

void insertData() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
			if (a[i][k] == 2) {
				canvi.push_back(make_pair(i, k));
			}
		}
	}
}

int main() {
	insertData();
	sort(canvi.begin(), canvi.end());
	int ans = 2147483647;
	vector<bool> temp(canvi.size());
	for (int i = 0; i < m; i++)
		temp[i] = true;

	do {
		for (int i = 0; i < canvi.size(); ++i) {
			if (temp[i]) {
				int y = canvi[i].first;
				int x = canvi[i].second;
				a[y][x] = 3;
			}
		}
		int k = bfs();
		if (ans > k && k != -1) ans = k;

		for (int i = 0; i < canvi.size(); ++i) {
			if (temp[i]) {
				int y = canvi[i].first;
				int x = canvi[i].second;
				a[y][x] = 2;
			}
		}
	} while (prev_permutation(temp.begin(), temp.end()));

	if (ans == 2147483647) cout << "-1";
	else cout << ans;
}