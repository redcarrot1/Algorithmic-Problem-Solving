#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//±íÀÌ ¿ì¼± Å½»ö(DFS)
vector<int> a[1001];
int n;
int check1[1001];

void dfs(int x) {
	check1[x] = true;
	//cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check1[y] == false) {
			dfs(y);
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
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int m, start;
	cin >> n >> m;
	insertData(m);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (check1[i] == false) {
			dfs(i);
			ans++;
		}
	}
	cout << ans;

}