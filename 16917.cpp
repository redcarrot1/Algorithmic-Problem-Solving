#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//�ݹ� ������ �������� ���� �Ķ��̵� ������ �ڵ����� ��������.
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