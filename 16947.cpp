#include <iostream>
#include <queue>
using namespace std;
int n;
vector<int>a[3000];
int check[3000];

int dfs(int x, int p) {
	if (check[x] == 1) return x;
	check[x] = 1;

	for (int y : a[x]) {
		if (y == p) continue;
		int res = dfs(y, x);
		if (res >= 0) {
			check[x] = 2;
			if (x == res) return -2;
			else return res;
		}
		if (res == -2) return -2;
	}
	return -1;
}
void insertData() {
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		x -= 1; y -= 1;
		a[x].push_back(y);
		a[y].push_back(x);
	}
}
int main() {
	insertData();
	dfs(0, -1);
	int dist[3000] = { 0, };
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (check[i] == 2) {
			q.push(i);
			dist[i] = 1;
			//cout << i << " ";
		}
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (dist[y] == 0) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dist[i] - 1 << " ";
	}
}