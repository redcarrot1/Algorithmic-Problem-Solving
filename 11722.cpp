#include <iostream>
using namespace std;

int d[1001];
int arr[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int k = 0; k < i; k++) {
			if (arr[i] < arr[k] && d[i] < d[k] + 1) d[i] = d[k] + 1;
		}
	}

	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (temp < d[i]) temp = d[i];
	}



	cout << temp;
}