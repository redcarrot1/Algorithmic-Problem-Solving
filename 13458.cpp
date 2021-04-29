#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, k;
	vector<long long> v;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	long long b, c;
	cin >> b >> c;

	long long total = 0;
	for (long long i = 0; i < n; i++) {
		v[i] -= b;
		total += 1;
		
		if (v[i] > 0) {
			if (v[i] % c != 0) total += 1;
			total += v[i] / c;
		}
	}
	cout << total;
}