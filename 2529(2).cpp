#include <iostream>
#include <algorithm>
using namespace std;

int k;
char a[9];
int b[10];

//next_permutation -> 오름차순 해놔야함
//prev_permutation -> 내림차순 해놔야함
void high() {
	for (int i = 0; i < k + 1; i++) {
		b[i] = 9 - i;
	}

	do {
		for (int i = 0; i < k + 1; i++) {
			if (i == k) {
				for (int q = 0; q < k + 1; q++) {
					cout << b[q];
				}
				cout << '\n';
				return;
			}

			if (a[i] == '<') {
				if (b[i] > b[i + 1]) break;
			}
			if (a[i] == '>') {
				if (b[i] < b[i + 1]) break;
			}
		}
	} while (prev_permutation(b, b + k + 1));
}

void low() {
	for (int i = 0; i < k + 1; i++) {
		b[i] = i;
	}

	do {
		for (int i = 0; i < k + 1; i++) {
			if (i == k) {
				for (int q = 0; q < k + 1; q++) {
					cout << b[q];
				}
				cout << '\n';
				return;
			}

			if (a[i] == '<') {
				if (b[i] > b[i + 1]) break;
			}
			if (a[i] == '>') {
				if (b[i] < b[i + 1]) break;
			}
		}
	} while (next_permutation(b, b + k + 1));
}

int main() {
	cin >> k;
	char c;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	//최댓값
	high();
	low();
}