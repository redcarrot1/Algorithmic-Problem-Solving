#include <iostream>
//14888, 15658 °ø¿ë
using namespace std;

int n, a[100];
int maxs = -1000000000;
int mins = 1000000000;
int op[4];
int useop[4];


void go(int index, int num) {
	if (index == n-1) {
		if (num > maxs) maxs = num;
		if (num < mins) mins = num;
		return;
	}

	if (op[0] != useop[0]) {
		useop[0] += 1;
		go(index + 1, num + a[index + 1]);
		useop[0] -= 1;
	}
	if (op[1] != useop[1]) {
		useop[1] += 1;
		go(index + 1, num - a[index + 1]);
		useop[1] -= 1;
	}
	if (op[2] != useop[2]) {
		useop[2] += 1;
		go(index + 1, num * a[index + 1]);
		useop[2] -= 1;
	}
	if (op[3] != useop[3]) {
		useop[3] += 1;
		go(index + 1, num / a[index + 1]);
		useop[3] -= 1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	go(0, a[0]);
	cout << maxs << '\n' << mins;

}