#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
set<int> v[201];
int ans = 0;

void go(int cnt, int x1, int x2, int x3) {
	if (cnt == n + 1) return;

	//���� �ϳ��� ���� ���ߴٸ�
	if (x1 == 0) {
		go(cnt + 1, cnt, 0, 0); //����
		go(cnt + 1, 0, 0, 0); //����x
	}

	//�Ѱ�����
	else if (x2 == 0) {
		if (v[cnt].count(x1) == 0) go(cnt + 1, x1, cnt, 0); //����
		go(cnt + 1, x1, 0, 0); //����x
	}

	//�ΰ�����
	else if (x3 == 0) {
		go(cnt + 1, x1, x2, 0); //����x
		if (v[cnt].count(x1) == 0 && v[cnt].count(x2) == 0) { //���� -> ��
			ans += 1;
			return;
		}
	}
}
int main() {
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].insert(y);
		v[y].insert(x);
	}

	go(1, 0, 0, 0);
	cout << ans;
}