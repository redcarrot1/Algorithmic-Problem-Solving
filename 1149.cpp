#include <iostream>
using namespace std;

int arr[1000][3];
int d[1000][3];
int n;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> arr[i][k];
		}
	}
	for (int i = 1; i <= n; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + arr[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + arr[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + arr[i][2];
	}

	cout << min({ d[n][0], d[n][1], d[n][2] });

}