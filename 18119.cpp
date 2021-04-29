#include <iostream>
#include <string>
using namespace std;

string str;
long long bit[10001]{};
int n, m;
long long s = 0;

void set() {
	for (int i = 0; i < 26; i++) {
		s = s | (1 << i);
	}
}

void insertdata() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (char q : str) {
			int x = q - 'a';
			bit[i] = bit[i] | (1 << x);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	insertdata();
	set();

	int order, ch;
	char c;

	for (int i = 0; i < m; i++) {
		int ans = 0;
		cin >> order >> c;
		ch = c - 'a';

		if (order == 1) {
			s = s & ~(1 << ch);
		}
		else if (order == 2) {
			s = s | (1 << ch);
		}

		for (int k = 0; k < n; k++) {
			if ((bit[k] & s) == bit[k]) ans += 1;
		}
		cout << ans << "\n";
	}
}