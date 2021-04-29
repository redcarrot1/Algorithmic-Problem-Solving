/*
0-1배낭 문제
Knapsack Problem

P[i, w]=무게 w에 따른 i번째 물건까지의 총 가치의 최대치
w[i]=i번 물건의 무게
v[i]=i번 물건의 가치

//i번째 무게가 w보다 크다면 못넣는다.
if(w[i]>w){
	p[i, w] = p[i-1, w]
	}
else{
	1. i번째 물건을 넣는다. -> p[i, w]=v[i]+p[i-1, w-wi]
	2. i번째 물건을 안넣는다 -> p[i-1, w]
	}

점화식: p[i, w]= max(v[i]+p[i-1, w-w[i]], p[i-1, w]) (단, w[i]>w이면 무조건 p[i, w] = p[i-1, w])

위 점화식을 이용하여 dp로 풀면된다.

for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0) {
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
	}
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v[101], w[101], d[101][1000];
int limitW, n;

int main() {
	cin >> n >> limitW;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= limitW; k++) {
			d[i][k] = 10000000;
		}
	}
	//본 문제는 최소값을 찾는 문제이므로 max대신 min을 사용한다.
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= limitW; j++) {
			d[i][j] = d[i - 1][j];
			if (j - w[i] >= 0) {
				d[i][j] = min(d[i][j], d[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	cout << d[n][limitW];
}