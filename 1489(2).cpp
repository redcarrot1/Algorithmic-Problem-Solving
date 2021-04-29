#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[20][20];
int n, ans = 2147483647;

void comb() {
	int b[20] = { 0, };
	for (int i = 0; i < n / 2; i++) {
		b[i] = 1;
	}
	sort(b, b+n);
	do {
		int sum1 = 0;
		int sum2 = 0;

		vector<int> first, second;
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}

		for (int k = 0; k < n / 2; k++) {
			for (int q = 0; q < n / 2; q++) {
				sum1 += a[first[k]][first[q]];
				sum2 += a[second[k]][second[q]];
			}
		}


		int diff = sum1 - sum2;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(b, b+n));
}

void insertData() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
		}
	}
}
int main() {
	insertData();
	comb();
	cout << ans;
}