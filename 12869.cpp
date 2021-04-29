#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int k, l, m;
int d[61][61][61];

/*
1. 문제의 최소문제 정의 (ex if(n==1) return 0;)
2. 메모가 되있다면 그거 사용 (ex if (memo[n] > 0) return memo[n];)
3. 아니라면 문제 풀어서 그 값 리턴.(ex memo[n]=max(go(n-1), go(n-2))+a[n]; return memo[n];)
재귀 함수의 인자는 주로 d배열의 차원과 같다.
*/


int go(int a, int b, int c) {
	if (a < 0) a = 0;
	if (b < 0) b = 0;
	if (c < 0) c = 0;

	if (a == 0 && b == 0 && c == 0) return 0;
	if (d[a][b][c] != 0) return d[a][b][c];

	d[a][b][c] = 29999999;
	int temp= go(a - 9, b - 3, c - 1)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	temp = go(a - 9, b - 1, c - 3)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	temp = go(a - 1, b - 3, c - 9)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	temp = go(a - 1, b - 9, c - 3)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	temp = go(a - 3, b - 1, c - 9)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	temp = go(a - 3, b - 9, c - 1)+1;
	if (d[a][b][c] > temp) d[a][b][c] = temp;

	return d[a][b][c];

}

int main() {
	k = 0; l = 0; m = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		if (i == 0) cin >> k;
		else if (i == 1) cin >> l;
		else cin >> m;
	}
	cout<<go(k, l, m);
	
}