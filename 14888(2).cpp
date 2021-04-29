#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[11];
int mins = 2147483647;
int maxs = -2147483647;
vector<int> v;

void circ() {
	do {
		int sum = a[0];
		for (int i = 0; i < n - 1; i++) {
			if (v[i] ==0) {
				sum = sum + a[i + 1];
			}
			else if (v[i] ==1) {
				sum = sum - a[i + 1];
			}
			else if (v[i] == 2) {
				sum = sum * a[i + 1];
			}
			else if (v[i] == 3) {
				sum = sum / a[i + 1];
			}
		}
		if (sum < mins) mins = sum;
		if (sum > maxs) maxs = sum;
	} while (next_permutation(v.begin(), v.end()));
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		int k;
		cin >> k;
		for (int q = 0; q < k; q++) {
			v.push_back(i);
		}
	}
	circ();
	cout << maxs << '\n' << mins;
}