#include <iostream>
#include <algorithm>
using namespace std;

int w[10][10];
int n;
int arr[10];
void insertData() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> w[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		arr[i] = i;
	}
}

int main() {
	int min = 2147483647;
	insertData();

	do {
		int sum = 0;
		bool ok = true;
		for (int i = 1; i < n; i++) {
			if (w[arr[i - 1]][arr[i]] == 0) {
				ok = false;
				break;
			}
			sum += w[arr[i - 1]][arr[i]];
		}
		if (ok && w[arr[n - 1]][arr[0]] != 0) {
			sum += w[arr[n - 1]][arr[0]];
			if (min > sum) min = sum;
		}
	} while (next_permutation(arr + 1, arr + n));

	cout << min;
}