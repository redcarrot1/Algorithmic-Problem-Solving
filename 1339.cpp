#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, jo = 1;
int a[26];
string str[10];
int ans = 0;

void go() {
	int b[11];
	for (int i = 1; i < jo; i++) {
		b[i] = 10 - i;
	}

	do {
		int total = 0;
		for (string c : str) {
			int sum = 0;
			for (char x : c) {
				sum = sum * 10 + b[a[x - 'A']];
			}
			total += sum;
		}
		if (ans < total) ans = total;
	} while (prev_permutation(b + 1, b + jo));
}

void set() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < str[i].length(); k++) {
			if (a[str[i][k] - 'A'] == 0) {
				a[str[i][k] - 'A'] = jo;
				jo += 1;
			}
		}
	}
}
int main() {
	set();
	go();
	cout << ans;
}