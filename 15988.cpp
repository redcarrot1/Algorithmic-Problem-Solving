#include <iostream>
using namespace std;
#define mod 1000000009

long long d[1000001];

int main() {
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;

	for (int i = 4; i <= 1000001; i++) {
		d[i] = d[i - 1]%mod + d[i - 2] % mod + d[i - 3] % mod;
		d[i] %= mod;
	}

	int t;
	cin >> t;
	int n;
	while (t--) {
		cin >> n;
		cout << d[n]<<'\n';
	}


}