#include <iostream>
using namespace std;

int main() {
	int n, t;
	cin >> t;

	int d[12];
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 10; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	while (t--) {
		cin >> n;

		cout << d[n]<<'\n';
	}
}