#include <iostream>
using namespace std;

int go(int sum, int n) {
	if (sum > n) { return 0; }
	if (sum == n) { return 1; }
	int ans = 0;

	for (int i = 1; i <= 3; i++) {
		ans+=go(sum + i, n);
	}
	return ans;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
}