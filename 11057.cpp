#include <iostream>
using namespace std;
const int mod = 10007;

int d[1000][10];
int n;

int main() {
	cin >> n;
	
	for (int i = 0; i < 10; i++) {
		d[1][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 10; k++) {
			for (int j = 0; j <= k; j++) {
				d[i][k] += d[i - 1][j];
				d[i][k] %= mod;
			}
		}
	}

	int temp = 0;
	for (int i = 0; i < 10; i++) {
		temp += d[n][i];
		temp %= mod;
	}
	cout << temp;
}