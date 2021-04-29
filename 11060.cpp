#include <iostream>
using namespace std;

int n, a[1001], d[1001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	fill_n(d, 1001, -1);
	d[1] = 0;

	for (int i = 1; i <= n - 1; i++) {
		if (d[i] == -1) continue;
		for (int k = 1; k <= a[i]; k++) {
			if (i + k > n) break;
			if (d[i + k] == -1 || d[i + k] > d[i] + 1) {
				d[i + k] = d[i] + 1;
			}
		}
	}
	cout << d[n];;
}