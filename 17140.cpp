#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int row = 3, col = 3; //행(가로줄) 열(세로줄)
//A[r][c]에 들어있는 값이 k가 되기 위한 최소 시간을 구해보자.
int a[101][101], r, c, k;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void rop() {
	vector<pair<int, int>> v[101];
	int len = 0;
	for (int i = 0; i < row; i++) {
		//i번 행을 작업할겁니다.
		int temp[101]{};

		//i번 행의 빈도수를 봅시다
		int bignum = 1;
		for (int k = 0; k < col; k++) {
			temp[a[i][k]] += 1;
			if (bignum < a[i][k]) bignum = a[i][k];
		}

		//(숫자, 빈도수)형식으로 v[i]에 저장해줍시다.
		for (int k = 1; k <= bignum; k++) {
			if (temp[k] != 0) {
				v[i].push_back(make_pair(k, temp[k]));
			}
		}
		//제일 긴 배열을 찾기위해 len을 사용해줍시다.
		if (len < v[i].size() * 2) len = v[i].size() * 2;
		sort(v[i].begin(), v[i].end(), cmp);
	}

	if (len > 100) len = 100;
	//이제 v에 모든 정렬한 숫자들이 있으니 a에 복사해줍시다.
	//제일 긴 배열의 길이인 len보다 짧으면 나머지엔 0을 채웁시다.
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < v[i].size(); k++) {
			if (2 * k >= 100) break;
			a[i][2 * k] = v[i][k].first;
			a[i][2 * k + 1] = v[i][k].second;
		}
		for (int k = 2 * v[i].size(); k < len; k++) {
			a[i][k] = 0;
		}
	}
	col = len;
}

void cop() {
	vector<pair<int, int>> v[101];
	int len = 0;
	for (int i = 0; i < col; i++) {
		//i번 열을 작업할겁니다.
		int temp[101]{};

		//i번 열의 빈도수를 봅시다
		int bignum = 1;
		for (int k = 0; k < row; k++) {
			temp[a[k][i]] += 1;
			if (bignum < a[k][i]) bignum = a[k][i];
		}

		//(숫자, 빈도수)형식으로 v[i]에 저장해줍시다.
		for (int k = 1; k <= bignum; k++) {
			if (temp[k] != 0) {
				v[i].push_back(make_pair(k, temp[k]));
			}
		}
		//제일 긴 배열을 찾기위해 len을 사용해줍시다.
		if (len < v[i].size() * 2) len = v[i].size() * 2;

		sort(v[i].begin(), v[i].end(), cmp);
	}

	if (len > 100) len = 100;
	//이제 v에 모든 정렬한 숫자들이 있으니 a에 복사해줍시다.
	//제일 긴 배열의 길이인 len보다 짧으면 나머지엔 0을 채웁시다.
	for (int i = 0; i < col; i++) {
		for (int k = 0; k < v[i].size(); k++) {
			if (2 * k >= 100) break;
			a[2 * k][i] = v[i][k].first;
			a[2 * k + 1][i] = v[i][k].second;
		}
		for (int k = 2 * v[i].size(); k < len; k++) {
			a[k][i] = 0;
		}
	}
	row = len;

}

void print() {
	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cout << a[i][k] << " ";
		}
		cout << "\n";
	}
}

void insertdata() {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			cin >> a[i][k];
		}
	}
	r -= 1;
	c -= 1;
}
int main() {
	insertdata();
	int ans = 0;
	while (1) {
		if (ans == 101) {
			cout << "-1"; return 0;
		}
		if (a[r][c] == k) break;
		if (row >= col) rop();
		else cop();
		ans += 1;
		//cout << "\n======" << ans << "=======\n";
		//print();
	}
	cout << ans;
}