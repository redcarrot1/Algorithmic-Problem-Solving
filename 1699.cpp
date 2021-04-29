#include <iostream>
using namespace std;
int arr[100000];
int d[100000];
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > d[i - j * j] + 1) {
				d[i] = d[i - j * j] + 1;
			}
		}
	}
	cout << d[n];
}