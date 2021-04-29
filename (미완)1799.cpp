#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> can;
int n, ans = 0;

vector<vector<int>> update(int i, int k, vector<vector<int>> b) {
	int nx = k + 1, ny = i + 1;
	b[i][k] = -1;
	while (1) {
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		b[ny++][nx++] = -1;
	}

	nx = k - 1; ny = i - 1;
	while (1) {
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		b[ny--][nx--] = -1;
	}

	nx = k - 1; ny = i + 1;
	while (1) {
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		b[ny++][nx--] = -1;
	}

	nx = k + 1; ny = i - 1;
	while (1) {
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) break;
		b[ny--][nx++] = -1;
	}
	return b;
}

void go(int cnt, int su, vector<vector<int>> b) {
	if (cnt == can.size()) {
		if (ans < su) ans = su;
		return;
	}
	
	if (b[can[cnt].first][can[cnt].second] != -1) {
		go(cnt + 1, su + 1, update(can[cnt].first, can[cnt].second, b));
	}
	go(cnt + 1, su, b);
	
}

int main() {
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
			if (a[i][k] == true) can.push_back(make_pair(i, k));
		}
	}

	go(0, 0, a);
	cout << ans;
}