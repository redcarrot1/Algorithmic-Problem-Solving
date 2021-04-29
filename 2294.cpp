#include <iostream>
using namespace std;

int n, m, d[10001], value[101];

int main() {
	cin >> n >> m;

	int es = 10000000;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}
	d[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= m; k++) {
			if (k - value[i] < 0) continue;
			d[k] += d[k - value[i]];
		}
	}

	cout << d[m];
}