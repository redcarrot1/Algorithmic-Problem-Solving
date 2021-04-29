#include <iostream>
using namespace std;
const long long mod = 1000000009LL;
const int limit = 100000;

int main() {
	long long d[100000][4];
	for (int i = 1; i <= limit; i++) {
		if (i - 1 >= 0) {
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1) {
				d[i][1] = 1;
			}
		}
		if (i - 2 >= 0) {
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2) {
				d[i][2] = 1;
			}
		}
		if (i - 3 >= 0) {
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3) {
				d[i][3] = 1;
			}
		}
		d[i][1] %= mod;
		d[i][2] %= mod;
		d[i][3] %= mod;
	}
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3])%mod << '\n';
	}
}