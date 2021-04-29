#include <iostream>
using namespace std;

int n, t, d[10001];

int main() {
	d[0] = 1;
	d[1] = 1;

	for (int i = 1; i <= 3; i++) {
		for (int k = 2; k < 10001; k++) {
			if (k - i < 0) continue;
			d[k] += d[k - i];
		}
	}


	cin >> t;
	while (t--) {
		cin >> n;
		cout << d[n] << "\n";
	}
}