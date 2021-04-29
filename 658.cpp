#include <iostream>
using namespace std;

int arr[10000];
int d[10000][3];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	d[1][0] = 0;
	d[1][1] = arr[1];
	d[1][2] = arr[1];

	for (int i = 2; i <= n; i++) {
		d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2] );
		d[i][1] = d[i - 1][0] + arr[i];
		d[i][2] = d[i - 1][1] + arr[i];
	}
	cout << max(max(d[n][0], d[n][1]), d[n][2]);
}