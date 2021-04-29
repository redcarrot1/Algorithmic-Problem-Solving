#include <iostream>
#include <string>
using namespace std;
const int mod = 1000000;

int d[5000][2];
int main() {
	string s;

	cin >> s;
	if (s[0]=='0') { cout << "0"; return 0; }

	d[0][0] = 1;
	d[0][1] = 0;
	for (int i = 1; i < s.size(); i++) {
		if(s[i]-'0'!=0) d[i][0] = d[i - 1][0] + d[i - 1][1];
		if (10<=s[i] - '0' + 10 * (s[i - 1] - '0') && (s[i] - '0' + 10 * (s[i - 1] - '0')) <= 26) d[i][1] = d[i - 1][0];
		d[i][0] %= mod;
		d[i][1] %= mod;
	}
	cout << (d[s.size() - 1][0] + d[s.size() - 1][1]) %mod;
}	