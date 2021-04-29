/*
0-1�賶 ����
Knapsack Problem

P[i, w]=���� w�� ���� i��° ���Ǳ����� �� ��ġ�� �ִ�ġ
w[i]=i�� ������ ����
v[i]=i�� ������ ��ġ

//i��° ���԰� w���� ũ�ٸ� ���ִ´�.
if(w[i]>w){
	p[i, w] = p[i-1, w]
	}
else{
	1. i��° ������ �ִ´�. -> p[i, w]=v[i]+p[i-1, w-wi]
	2. i��° ������ �ȳִ´� -> p[i-1, w]
	}

��ȭ��: p[i, w]= max(v[i]+p[i-1, w-w[i]], p[i-1, w]) (��, w[i]>w�̸� ������ p[i, w] = p[i-1, w])

�� ��ȭ���� �̿��Ͽ� dp�� Ǯ��ȴ�.

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
	//�� ������ �ּҰ��� ã�� �����̹Ƿ� max��� min�� ����Ѵ�.
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