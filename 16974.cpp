#include <iostream>
using namespace std;

//레벨n버거의 사이즈
//d[n]=2*d[n-1]+3;

//x가 중간보다 작거나 같으면 n-1버거의 x-1장 먹은거다.
//x가 중간보다 크거나 같으면 n-1버거+n-1버거의 x-d[n-1]-2장 먹은거다.

long long d[51];
long long pn[51];

long long p(int level, long long x) {
	if (level == 0) {
		if (x == 0) return 0;
		else return 1;
	}
	else if (x == 1) return 0;

	else if (x <= d[level-1] +1) {
		return p(level - 1, x - 1);
	}
	else if (x == d[level-1] + 2) {
		return pn[level - 1] + 1;
	}
	else if (x<= 2+2*d[level-1]) {
		return pn[level - 1] + 1 + p(level - 1, x - 2-d[level-1]);
	} else {
		return 2 * pn[level - 1] + 1;
	}
}

int main() {
	int n;
	long long x;

	cin >> n >> x;

	d[0] = 1;
	pn[0] = 1;

	for (int i = 1; i <= n; i++) {
		d[i] = 2 * d[i - 1] + 3;
		pn[i] = 2 * pn[i - 1] + 1;
	}
	cout << p(n, x);
}