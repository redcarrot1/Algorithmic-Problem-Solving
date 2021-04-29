#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;
//([0]    �ùٸ����ڿ�(i-1)    )[i]     �ùٸ����ڿ�(L-i-2)

//d[i]: ���̰� i�϶� �ùٸ� ��ȣ ���ڿ� ����
long long d[5001];
long long mod = 1000000007LL;

long long go(int l) {
	if (d[l] != 0) return d[l];

	for (int i = 1; i < l; i += 2) {
		d[l] += go(i-1) * go(l - i - 1);
		d[l] %= mod;
	}

	d[l] %= mod;
	return d[l];
}
int main() {
	int t;
	cin >> t;

	d[0] = 1;
	d[2] = 1;
	d[4] = 2;
	
	while (t--) {
		int n;
		cin >> n;
		if (n % 2 != 0) cout << "0" << "\n";
		else cout << go(n)<<'\n';
	}
}