#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int n;
	int d[2][3][2];
	cin >> n;
	int q;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 3; k++) {
			if (i == 0) {
				cin >> d[0][k][0];
				d[0][k][1] = d[0][k][0];
			}
			else {
				cin >> q;
				if (i % 2 == 0) {
					if (k == 0)d[0][0][0] = max(d[1][0][0], d[1][1][0]) + q;
					else if (k == 1)d[0][1][0] = max(max(d[1][0][0], d[1][1][0]), d[1][2][0]) + q;
					else if (k == 2)d[0][2][0] = max(d[1][1][0], d[1][2][0]) + q;

					if (k == 0)d[0][0][1] = min(d[1][0][1], d[1][1][1]) + q;
					else if (k == 1)d[0][1][1] = min(min(d[1][0][1], d[1][1][1]), d[1][2][1]) + q;
					else if (k == 2)d[0][2][1] = min(d[1][1][1], d[1][2][1]) + q;
				}
				else {
					if (k == 0)d[1][0][0] = max(d[0][0][0], d[0][1][0]) + q;
					else if (k == 1)d[1][1][0] = max(max(d[0][0][0], d[0][1][0]), d[0][2][0]) + q;
					else if (k == 2)d[1][2][0] = max(d[0][1][0], d[0][2][0]) + q;

					if (k == 0)d[1][0][1] = min(d[0][0][1], d[0][1][1]) + q;
					else if (k == 1)d[1][1][1] = min(min(d[0][0][1], d[0][1][1]), d[0][2][1]) + q;
					else if (k == 2)d[1][2][1] = min(d[0][1][1], d[0][2][1]) + q;
				}
			}
		}
	}


	if (n % 2 == 0) {
		cout << max(max(d[1][0][0], d[1][1][0]), d[1][2][0]) << " ";
		cout << min(min(d[1][0][1], d[1][1][1]), d[1][2][1]);
	}
	else {
		cout << max(max(d[0][0][0], d[0][1][0]), d[0][2][0]) << " ";
		cout << min(min(d[0][0][1], d[0][1][1]), d[0][2][1]);
	}
}