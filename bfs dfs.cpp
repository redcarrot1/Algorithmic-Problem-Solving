#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//±íÀÌ ¿ì¼± Å½»ö(DFS)
int check[100];
vector<int> a[100];

void dfs(int x) {
	check[x] = true;
	for (int i = 1; i <= a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

//³Êºñ ¿ì¼± Å½»ö
void bfs(int x) {
	queue<int> q;
	check[1] = true;
	q.push(1);

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check[y] == false) {
				check[y] = true; q.push(y);
			}
		}
	}
}