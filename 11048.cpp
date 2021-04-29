#include <iostream>
using namespace std;
int h, w, d[1001][1001]{}, a[1001][1001]{};

int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int k = 1; k <= w; k++) {
			cin >> a[i][k];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int k = 1; k <= w; k++) {
			d[i][k] = max(d[i-1][k], d[i][k - 1]) + a[i][k];
		}
	}
	cout << d[h][w];
}