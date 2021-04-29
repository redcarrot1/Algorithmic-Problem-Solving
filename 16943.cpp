#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	string a;
	int b;
	cin >> a >> b;

	sort(a.begin(), a.end());
	int ans = -1;
	if (stoi(a) > b) {
		cout << "-1";
		return 0;
	}

	do {
		if (a[0] != '0') {
			if(stoi(a) <= b) {
				ans = max(ans, stoi(a));
			}
			else break;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << ans;
}