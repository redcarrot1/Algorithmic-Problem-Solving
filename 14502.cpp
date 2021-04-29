#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m; //세로, 가로
int a[8][8];
int visit[8][8];
int mo[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };


int dfs() {

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = a[i][j];
			if (visit[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + mo[i][0];
			int cy = y + mo[i][1];
			if (0 <= cx && cx < m && 0 <= cy && cy < n) {
				if (visit[cy][cx] != 0) continue;
				visit[cy][cx] = 2;
				q.push(make_pair(cy, cx));
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (visit[i][k] == 0) cnt++;
		}
	}
	return cnt;

}

int main() {
	vector<pair<int, int>> v;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
			if (a[i][k] == 0) v.push_back(make_pair(i, k));
		}
	}

	
	for (int l = 0; l< v.size() - 2; l++) {
		for (int m = l+1; m < v.size() - 1; m++) {
			for (int s = m+1; s < v.size(); s++) {
				a[v[l].first][v[l].second] = 1;
				a[v[m].first][v[m].second] = 1;
				a[v[s].first][v[s].second] = 1;

				int cnt = dfs();

				a[v[l].first][v[l].second] = 0;
				a[v[m].first][v[m].second] = 0;
				a[v[s].first][v[s].second] = 0;
				if (ans < cnt) ans = cnt;
			}
		}
	}

	cout << ans;
}