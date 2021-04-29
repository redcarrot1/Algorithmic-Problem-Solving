#include <iostream>
using namespace std;

int t[15];
int p[15];
int n;
int maxium = 0;


void go(int sum, int day) {
	if (day == n) {
		if (maxium < sum) maxium = sum;
		return;
	}
	else if (day > n) return;

	go(sum + p[day], day + t[day]);
	go(sum, day + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];
	}
	go(0, 0);
	cout << maxium;
}