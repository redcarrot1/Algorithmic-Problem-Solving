#include <iostream>
using namespace std;

int main() {
	long long d[101];

	int t, n;
	cin >> t;
	d[1] = 1;
	d[2] = 1;
	d[3] = 1;
	d[4] = 2;
	d[5] = 2;
	d[6] = 3;
	d[7] = 4;
	d[8] = 5;
	d[9] = 7;
	d[10] = 9;
	d[11] = 12;
	d[12] = 16;

	for (int i = 13; i <= 100; i++) {
		d[i] = d[i - 5] + d[i - 1];
	}

	while (t--) {
		cin >> n;
		cout << d[n] << '\n';
	}


}