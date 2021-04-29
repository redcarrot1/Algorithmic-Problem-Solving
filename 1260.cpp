#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//±íÀÌ ¿ì¼± Å½»ö(DFS)
vector<int> a[1001];
int n;
int check1[1001];
int check2[1001];

void dfs(int x) {
	check1[x] = true;
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check1[y] == false) {
			dfs(y);
		}
	}
}

//³Êºñ ¿ì¼± Å½»ö
void bfs(int x) {
	cout << x << " ";
	queue<int> q;
	check2[x] = true;
	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check2[y] == false) {
				cout << y << " ";
				check2[y] = true; q.push(y);
			}
		}
	}
}
void insertData(int m) {
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
}
int main() {
	int m, start;
	cin >> n >> m >> start;
	insertData(m);
	

	dfs(start);
	cout << "\n";
	bfs(start);
}