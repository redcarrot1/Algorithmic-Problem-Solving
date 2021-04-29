#include <iostream>
using namespace std;


int memo[1000001];

int dp(int n) {
	if (n == 1) return 0;
	if (memo[n] > 0) return memo[n];

	memo[n] = dp(n - 1) + 1;

	if (n % 3 == 0) {
		int temp = dp(n / 3) + 1;
		if (temp < memo[n]) memo[n] = temp;
	}
	if (n % 2 == 0) {
		int temp = dp(n / 2) + 1;
		if (temp < memo[n]) memo[n] = temp;
	}
	return memo[n];
}
int main() {
	int n;
	cin >> n;
	dp(n);
	cout << memo[n];
}