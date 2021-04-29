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
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
2. 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
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
	//m번 학생을 배치할 차례이다.
	int mostlikePepleNum = 0;
	int likePepleNum = 0;
	int mostblank = 0;
	int blank = 0;
	int y=0, x=0;
	//3번 조건을 위해 오른쪽 하단부터 스캔
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