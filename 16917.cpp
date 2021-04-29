#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//반반 개수가 정해지면 양념과 후라이드 개수도 자동으로 정해진다.
	int a, b, c;
	int x, y;
	cin >> a >> b >> c >> x >> y;

	long long ans = x * a + y * b;
	for (int i = 1; i <= 100000; i++) {
		long long k = 2 * i * c + max(0, x - i) * a + max(0, y - i) * b;
		if (ans > k) ans = k;
	}
	cout << ans;
}