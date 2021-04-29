#include <iostream>
using namespace std;

int d[1001];
int v[1001];
int arr[1001];


void go(int i) {
	if (i == -1) return;
	go(v[i]);
	cout << arr[i]<<' ';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	fill_n(d, n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int temp = 0;
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (temp < d[i]) {
			temp = d[i];
			index = i;
		}
	}


	cout << temp<<'\n';
	go(index);
	cout << '\n';
}