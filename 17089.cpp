#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

set<int> s[4001];
int n;
int ans = 99999999;

void go(int x1, int x2, int x3) {
	if (x3 != 0) {
		int temp = s[x1].size() + s[x2].size() + s[x3].size() - 6;
		ans = min(ans, temp);
		return;
	}

	//x1의 친구들
	if (x2 == 0) {
		set<int>::iterator iter;
		for (iter = s[x1].begin(); iter != s[x1].end(); iter++) {
			//cout << *iter << " ";
			go(x1, *iter, 0);
		}
	}
	else if (x3 == 0) {
		for (int i = 1; i <= n; i++) {
			if (s[x1].count(i) == 1 && s[x2].count(i) == 1) {
				go(x1, x2, i);
			}
		}
	}
}

int main() {
	int m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}

	for (int i = 1; i <= n; i++) {
		if (s[i].size() < 2) continue;
		go(i, 0, 0);
	}

	if (ans == 99999999) cout << -1;
	else cout << ans;

}