#include <iostream>
using namespace std;

int n;
int a[20];
int s, ans;

void go(int index, int sum) {
	if (index == n) {
		if (sum == s) ans += 1;
		return;
	}

	go(index + 1, sum + a[index]);
	go(index + 1, sum);
}

int main() {
	cin >> n >> s;
	if (s == 0) ans -= 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);
	cout << ans;

}