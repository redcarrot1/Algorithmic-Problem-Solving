#include <iostream>
using namespace std;

int check[9];
int a[9];
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
		if (check[i] == true) continue;
		check[i] = true;
		a[index] = i;
		go(index + 1, i+1, n, m);
		check[i] = false;
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	go(0, 1, n, m);
}