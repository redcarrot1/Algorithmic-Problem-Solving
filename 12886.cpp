#include <iostream>
using namespace std;

int a[1501][1501];
int s, b;

void go(int x, int y, int z) {
	a[x][y] = true;
	if (x == y && y == z) {
		return;
	}


	//1.xy 2.yz 3.xz
	if (x > y) {
		int cy = y * 2;
		int cx = x - y;
		if (a[cx][cy] == 0) go(cx, cy, z);
	}
	else if (x < y) {
		int cy = y - x;
		int cx = 2 * x;
		if (a[cx][cy] == 0) go(cx, cy, z);
	}

	if (y > z) {
		int cy = y - z;
		int cz = 2 * z;
		if (a[x][cy] == 0) go(x, cy, cz);
	}
	else if (y < z) {
		int cy = 2 * y;
		int cz = z - y;
		if (a[x][cy] == 0) go(x, cy, cz);
	}

	if (x > z) {
		int cx = x - z;
		int cz = 2 * z;
		if (a[cx][y] == 0) go(cx, y, cz);
	}
	else if (x < z) {
		int cx = 2 * x;
		int cz = z - x;
		if (a[x][y] == 0) go(cx, y, cz);
	}
}

int main() {
	int m, n, b;
	cin >> m >> n >> b;
	s = m + n + b;
	a[m][n] = 1;

	if (s % 3 != 0) {
		cout << "0";
		return 0;
	}

	go(m, n, b);
	if (a[s / 3][s / 3] != 0) cout << "1";
	else cout << "0";
}