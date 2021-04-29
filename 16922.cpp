#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
bool a[21][1001];
int m[4] = { 1, 5, 10, 50 };

void go(int cnt, int sum) {

	if (n == cnt) {
		a[cnt][sum] = true;
		return;
	}

	if (a[cnt][sum] == true) return;
	a[cnt][sum]=true;
	for (int i = 0; i < 4; i++) {
		go(cnt + 1, sum + m[i]);
	}
}
int main() {
	cin >> n;
	go(0, 0);

	int ans = 0;
	for (int i = 1; i < 1001; i++) {
		if (a[n][i] == true) ans += 1;
	}
	cout << ans;
}