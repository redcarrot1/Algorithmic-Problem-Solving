#include <iostream>
using namespace std;

int arr[100000];
int d[100000];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	d[0] = arr[0];

	for (int i = 1; i < n; i++) {
		d[i] = arr[i];
		if (d[i] < d[i - 1] + arr[i]) {
			d[i] = d[i - 1] + arr[i];
		}
	}
	int temp = d[0];
	for (int i = 1; i < n; i++) {
		if (temp < d[i]) temp = d[i];
	}
	cout << temp;
}