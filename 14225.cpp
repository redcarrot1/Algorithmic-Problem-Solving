#include <iostream>
using namespace std;

int n;
int a[20];
bool c[20 * 100000];
int s, ans;

void go(int index, int sum) {
	if (index == n) {
		c[sum] = true;

		return;
	}

	go(index + 1, sum + a[index]);
	go(index + 1, sum);
}

int main() {
	cin >> n;
	if (s == 0) ans -= 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);
	for (int i = 1; i < 20 * 100000; i++) {
		if (c[i] == false) {
			cout << i;
			break;
		}
	}
}