#include <iostream>
#include <string>
using namespace std;
char bu[10];
bool check[10];
int k;
string minium = "9876543210";
string maxium = "0";

void go(string str, int index) {
	if (index == k+1) {
		if (minium > str) minium = str;
		if (maxium < str) maxium = str;
	}

	for (int i = 0; i <= 9; i++) {
		if (check[i]) continue;

		if (bu[index-1] == '<') {
			if (str[index-1] - '0' < i) {
				check[i] = true;
				go(str + to_string(i), index + 1);
				check[i] = false;
			}
		}
		else if (bu[index-1] == '>') {
			if (str[index-1] - '0' > i) {
				check[i] = true;
				go(str + to_string(i), index + 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> bu[i];
	}

	for (int i = 0; i <= 9; i++) {
		string str = to_string(i);
		if (i == 0) str = "0";
		check[i] = true;
		go(str, 1);
		check[i] = false;
	}

	cout << maxium << '\n' << minium;
}