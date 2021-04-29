#include <iostream>
#include <string>
using namespace std;

int s[10][10];
int arr[10];
int n;

void insertData() {
	cin >> n;
	char c;

	for (int i = 0; i < n; i++) {
		for (int k = i; k < n; k++) {
			cin >> c;
			if (c == '-') s[i][k] = -1;
			else if (c == '+') s[i][k] = 1;
			else s[i][k] = 0;
		}
	}
}

bool check(int index) {
	int sum = 0;
	for (int i = index; i >= 0; i--) {
		sum += arr[i];
		if (s[i][index] == 0) {
			if (sum != 0) return false;
		}
		else if (s[i][index] < 0) {
			if (sum >= 0) return false;
		}
		else if (s[i][index] > 0) {
			if (sum <= 0) return false;
		}
	}
	return true;
}

void go(int index) {
	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		exit(0);
	}

	if (s[index][index] == 1) {
		for (int i = 1; i <= 10; i++) {
			arr[index] = i;
			if (check(index)) go(index + 1);
			else continue;
		}
	}
	else if (s[index][index] == -1) {
		for (int i = 1; i <= 10; i++) {
			arr[index] = -i;
			if (check(index)) go(index + 1);
			else continue;
		}
	}
	else if (s[index][index] ==0) {
		arr[index] = 0;
		if (check(index)) go(index + 1);
		else return;
	}
}



int main() {
	insertData();
	go(0);
}