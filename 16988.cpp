#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int a[20][20];
int h, w;
vector< pair<int, int>> binkan;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = {-1, 1, 0, 0 };


int bfs(bool d[20][20], int i, int k) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, k));
	int flag = 0;
	d[i][k] = true;
	int count = 0;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		count += 1;
		

		for (int j = 0; j < 4; j++) {
			int ny = y + dy[j];
			int nx = x + dx[j];
			if (ny >= h || ny < 0 || nx >= w || nx < 0) continue;
			if (a[ny][nx] == 0) flag = 1;
			if (d[ny][nx] == true) continue;
			if (a[ny][nx] == 2) {
				d[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}

	}
	if (flag == 1) return 0;
	return count;
}

int go(int y1, int x1, int y2, int x2) {
	a[y1][x1] = 1;
	a[y2][x2] = 1;
	
	bool d[20][20]{};
	int c = 0;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if (a[i][k] == 2) {
				if (d[i][k] == true) continue;
				int temp = bfs(d, i, k);
				if (temp == 11) {
					bfs(d, i, k);
				}
				c += temp;
			}
		}
	}
	
	a[y1][x1] = 0;
	a[y2][x2] = 0;
	return c;
}


int main() {
	int ans = 0;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) binkan.push_back(make_pair(i, j));
		}
	}

	vector<bool> temp(binkan.size());
	for (int i = 0; i < 2; i++)
		temp[i] = true;

	do {
		int y1 = -1, x1, y2, x2;
		for (int i = 0; i < binkan.size(); ++i) {
			if (temp[i]) {
				if (y1 == -1) {
					y1 = binkan[i].first;
					x1 = binkan[i].second;
				}
				else {
					y2 = binkan[i].first;
					x2 = binkan[i].second;
				}
			}
		}
		int k = go(y1, x1, y2, x2);
		if (k == 3) {
			go(y1, x1, y2, x2);
		}

		if (ans < k) ans = k;
	} while (prev_permutation(temp.begin(), temp.end()));
	cout << ans;
}