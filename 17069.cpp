#include <iostream>
using namespace std;

long long d[33][33][3], a[33][33], n;

long long go() {
	//가로0 대각선1 세로2
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (a[i][j] == 1) continue;
			if (i == 1 && j == 2) continue;
			d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][1];

			if (i == 1) continue;
			d[i][j][2] = d[i - 1][j][1] + d[i - 1][j][2];

			if (a[i - 1][j] == 1 || a[i][j - 1] == 1) continue;
			d[i][j][1] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
		}
	}
	return d[n][n][0] + d[n][n][1] + d[n][n][2];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cin >> a[i][k];
		}
	}

	d[1][2][0] = 1;

	cout << go();
}