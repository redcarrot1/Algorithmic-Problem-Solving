#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	cin >> str;

	//숫자 10개
	//문자 26개

	int ans = 1;
	if (str[0] == 'd') ans = 10;
	else ans = 26;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == str[i - 1]) {
			if (str[i] == 'd') ans *= 9;
			else ans *= 25;
		}
		else {
			if (str[i] == 'd') ans *= 10;
			else ans *= 26;
		}
	}
	cout << ans;
}