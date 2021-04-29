#include <iostream>
using namespace std;

int arr[501][501];
int d[501][501];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			cin >> arr[i][k];
		}
	}


	d[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++) {
		for (int k = 1; k <= i; k++) {
			d[i][k] = d[i - 1][k] + arr[i][k];
			if (k >1 && d[i][k] < d[i - 1][k- 1] + arr[i][k]) {
				d[i][k] = d[i - 1][k - 1] + arr[i][k];
			}
		}
	}

	int temp = 0;
	for (int i = 1; i <= n; i++) {
		if (temp < d[n][i]) temp = d[n][i];
	}
	cout << temp;

}