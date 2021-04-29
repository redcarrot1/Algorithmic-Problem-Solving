#include<iostream>
using namespace std;

int gcd(long long a, long long b) {
	if (a % b == 0) {
		return b;
	}

	return gcd(b, a % b);
}

int main() {
	long long a, b;
	cin >> a >> b;

	long long result = gcd(a, b);
	for (int i = 0; i < result; i++) {
		cout << 1;
	}
	cout << endl;

	return 0;
}