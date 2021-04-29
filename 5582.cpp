#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
/*
if(Xi==Yj) {
마지막 문자가 같다면, 이전 LCS 문자열에서 마지막 문자열을 더하는게 무조건 이득이므로
LCS(i, j)=LCS(i-1, j-1) +1
}
else {
마지막 문자가 다르다면, (Xi가 포함 & Yi가 포함X) 이거나 (Xi가 포함X & Yi가 포함)인 LCS 중
큰 LCS를 취하면 된다)
LCS(i, j)= max(LCS(i, j-1), LCS(i-1, j))
}


LCS 중 하나 출력하기.
역추적 이용.
LCS(i, j)가 LCS(i-1, j-1)에서 왔는지, max(LCS(i, j-1), LCS(i-1, j))에서 왔는지 체크(Xi==Yi 라면 LCS(i-1, j-1)에서 온것)
LCS(i-1, j-1)에서 왔다면 Xi(혹은 Yi) 문자를 저장.
i==0 || j==0 이면 끝. (단, 문자열 맨 앞에 빈문자 추가해서 문자열은 인덱스 1부터 시작하게 만들기)
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