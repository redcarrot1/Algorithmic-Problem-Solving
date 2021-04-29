#include <iostream>
using namespace std;

//[전체 개수][본인의 1과 8의 개수의 합]
int d[101][10];

int main() {
	int n;
	cin >> n;

	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i - 1][1] % 1000000000;
		d[i][9] = d[i - 1][8] % 1000000000;
		for (int k = 1; k <= 8; k++) {
			d[i][k] = (d[i - 1][k - 1] + d[i - 1][k + 1]) % 1000000000;
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
		ans %= 1000000000;
	}
	cout << ans;
}
