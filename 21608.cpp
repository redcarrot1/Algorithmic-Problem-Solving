#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;

int n;
int a[21][21]{};
set<int> like[402];
int pri[402];
int ans = 0;

/*
1. ����ִ� ĭ �߿��� �����ϴ� �л��� ������ ĭ�� ���� ���� ĭ���� �ڸ��� ���Ѵ�.
2. 1�� �����ϴ� ĭ�� ���� ���̸�, ������ ĭ �߿��� ����ִ� ĭ�� ���� ���� ĭ���� �ڸ��� ���Ѵ�.
3. 2�� �����ϴ� ĭ�� ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ĭ����, �׷��� ĭ�� ���� ���̸� ���� ��ȣ�� ���� ���� ĭ���� �ڸ��� ���Ѵ�.
*/

void sati() {
	int people;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			people = 0;

			if (i + 1 < n) {
				people += like[a[i][k]].count(a[i + 1][k]);
			}

			if (k + 1 < n) {
				people += like[a[i][k]].count(a[i][k + 1]);
			}

			if (i - 1 >= 0) {
				people += like[a[i][k]].count(a[i - 1][k]);
			}

			if (k - 1 >= 0) {
				people += like[a[i][k]].count(a[i][k - 1]);
			}

			if (people == 1) ans += 1;
			else if (people == 2) ans += 10;
			else if (people == 3) ans += 100;
			else if (people == 4) ans += 1000;
		}
	}
}

void go(int m) {
	//m�� �л��� ��ġ�� �����̴�.
	int mostlikePepleNum = 0;
	int likePepleNum = 0;
	int mostblank = 0;
	int blank = 0;
	int y=0, x=0;
	//3�� ������ ���� ������ �ϴܺ��� ��ĵ
	for (int i = 0; i<n; i++) {
		for (int k = 0; k <n; k++) {
			if (a[i][k] != 0) continue;
			likePepleNum = 0;
			blank = 0;
			if (i + 1 < n) {
				if (a[i + 1][k] == 0) blank += 1;
				else likePepleNum += like[m].count(a[i + 1][k]);
			}
			if (i - 1 >= 0) {
				if (a[i - 1][k] == 0) blank += 1;
				else likePepleNum += like[m].count(a[i - 1][k]);
			}
			if (k + 1 < n) {
				if (a[i][k + 1] == 0) blank += 1;
				else likePepleNum += like[m].count(a[i][k + 1]);
			}
			if (k - 1 >= 0) {
				if (a[i][k - 1] == 0) blank += 1;
				else likePepleNum += like[m].count(a[i][k - 1]);
			}

			if (likePepleNum > mostlikePepleNum) {
				y = i;
				x = k;
				mostlikePepleNum = likePepleNum;
				mostblank = blank;
			}
			else if (likePepleNum == mostlikePepleNum) {
				if (blank > mostblank) {
					y = i;
					x = k;
					mostblank = blank;
				}
			}
		}
	}
	a[y][x] = m;
}

int main() {
	cin >> n;
	int temp;
	int person;
	for (int i = 0; i < n * n; i++) {
		cin >> temp;
		pri[i] = temp;
		for (int k = 0; k < 4; k++) {
			cin >> person;
			like[temp].insert(person);
		}
	}

	for (int i = 0; i < n * n; i++) {
		go(pri[i]);
	}

	sati();
	cout << ans;
}