#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int l, c;
string arr[15];

bool check(string str) {
	int ja = 0, mo = 0;
	for (int i = 0; i < l; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			mo++;
		}
		else ja++;
	}
	if (mo >= 1 && ja >= 2) return true;
	else return false;
}

void go(string str, int start, int usenum) {
	if (usenum < l && start == c) return;
	if (usenum == l) {
		if (check(str)) cout << str << '\n';
		else return;
	}
	for (int i = start; i < c; i++) {
		go(str + arr[i], i+1, usenum + 1);
	}
}

int main() {
	cin >> l >> c;
	char q;
	for (int i = 0; i < c; i++) {
		cin >> q;
		arr[i] = q;
	}
	sort(arr, arr + c);
	string str;
	go(str, 0, 0);
}