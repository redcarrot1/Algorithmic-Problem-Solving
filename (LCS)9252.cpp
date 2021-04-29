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

int d[1001][1001]{};
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
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}
	//cout << a<<"\n"<<b<<"\n";
	//for (int i = 0; i <alen; i++) {
	//	for (int j = 0; j < blen; j++) {
	//		cout << d[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << d[alen - 1][blen - 1]<<"\n";

	int i = alen - 1;
	int j = blen - 1;
	string ans = "";
	while (i != 0 && j != 0) {
		if (a[i] == b[j]) {
			ans+=a[i];
			i--; j--;
		}
		else {
			if (d[i][j] == d[i - 1][j]) {
				i--;
			}
			else j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
}