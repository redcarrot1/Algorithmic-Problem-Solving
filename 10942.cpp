#include <iostream>
#include <cstdio>
using namespace std;

int a[2001], d[2001][2001]; //d[i][j]: i번째부터 j번째까지 펠린드롬여부
int n;

int go(int x, int y) {
	if (d[x][y] != -1) return d[x][y];
	if (x == y) {
		return 1;
	}
	if (x + 1 == y) {
		if (a[x] == a[y]) {
			return 1;
		}
		else return 0;
	}
	if (a[x] != a[y]) return 0;
	return go(x + 1, y - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < 2001; i++) {
		for (int k = 0; k < 2001; k++) {
			d[i][k] = -1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int m;
	int x, y;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x -= 1; y -= 1;
		d[x][y]=go(x, y);
		cout << d[x][y] << '\n';
	}
}