#include <iostream>
using namespace std;

int n, a[501], d[501][501];

//d[i][j]=d[i][k]+d[k+1][j]+ (a[i]+..+a[j])
int go(int i, int j) {
	//if (i == 1 && j == n) return 0;
	if (i == j) return 0;
	if (d[i][j] != -1) return d[i][j];

	int asum = 0;
	for (int q = i; q <= j; q++) {
		asum += a[q];
	}

	int an = 2147483647;
	for (int q = i; q + 1 <= j; q++) {
		int k = go(i, q) + go(q + 1, j);
		if (k < an) an = k;
	}

	d[i][j] = an+asum;
	return d[i][j];

}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < 501; i++) {
			for (int k = 0; k < 501; k++) {
				d[i][k] = -1;
			}
		}
		go(1, n);
		cout << d[1][n] << '\n';

	}

}