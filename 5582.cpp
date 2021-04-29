#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
if(Xi==Yj) {
������ ���ڰ� ���ٸ�, ���� LCS ���ڿ����� ������ ���ڿ��� ���ϴ°� ������ �̵��̹Ƿ�
LCS(i, j)=LCS(i-1, j-1) +1
}
else {
������ ���ڰ� �ٸ��ٸ�, (Xi�� ���� & Yi�� ����X) �̰ų� (Xi�� ����X & Yi�� ����)�� LCS ��
ū LCS�� ���ϸ� �ȴ�)
LCS(i, j)= max(LCS(i, j-1), LCS(i-1, j))
}


LCS �� �ϳ� ����ϱ�.
������ �̿�.
LCS(i, j)�� LCS(i-1, j-1)���� �Դ���, max(LCS(i, j-1), LCS(i-1, j))���� �Դ��� üũ(Xi==Yi ��� LCS(i-1, j-1)���� �°�)
LCS(i-1, j-1)���� �Դٸ� Xi(Ȥ�� Yi) ���ڸ� ����.
i==0 || j==0 �̸� ��. (��, ���ڿ� �� �տ� ���� �߰��ؼ� ���ڿ��� �ε��� 1���� �����ϰ� �����)
*/

int d[4001][4001]{};
string a, b;

int main() {
	cin >> a >> b;
	a = " " + a;
	b = " " + b;


	int alen = a.size();
	int blen = b.size();
	for (int i = 1; i < alen; i++) {
		for (int j = 1; j < blen; j++) {

			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < alen; i++) {
		for (int j = 1; j < blen; j++) {
			if (ans < d[i][j]) {
				ans = d[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;

}