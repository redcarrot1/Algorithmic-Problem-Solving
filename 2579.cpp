#include <iostream>
using namespace std;

int main() {
	int map[301];
	int d[301];
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	d[0] = map[0];
	d[1] = map[1]+map[0];
	d[2] = max(map[0] + map[2], map[1] + map[2]);

	for (int i = 3; i < n; i++) {
		d[i] = max(d[i - 2] + map[i], d[i - 3] + map[i - 1] + map[i]);
	}

	cout << d[n-1];
}