#include <iostream>
#include <algorithm>
using namespace std;

int a[9];
int b[9];
void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i];
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		a[index] = b[i];
		go(index + 1, i, n, m);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int k;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		b[i] = k;
	}
	sort(b+1, b+1 + n);

	go(0, 1, n, m);
}