#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int row = 3, col = 3; //��(������) ��(������)
//A[r][c]�� ����ִ� ���� k�� �Ǳ� ���� �ּ� �ð��� ���غ���.
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
		//i�� ���� �۾��Ұ̴ϴ�.
		int temp[101]{};

		//i�� ���� �󵵼��� ���ô�
		int bignum = 1;
		for (int k = 0; k < col; k++) {
			temp[a[i][k]] += 1;
			if (bignum < a[i][k]) bignum = a[i][k];
		}

		//(����, �󵵼�)�������� v[i]�� �������ݽô�.
		for (int k = 1; k <= bignum; k++) {
			if (temp[k] != 0) {
				v[i].push_back(make_pair(k, temp[k]));
			}
		}
		//���� �� �迭�� ã������ len�� ������ݽô�.
		if (len < v[i].size() * 2) len = v[i].size() * 2;
		sort(v[i].begin(), v[i].end(), cmp);
	}

	if (len > 100) len = 100;
	//���� v�� ��� ������ ���ڵ��� ������ a�� �������ݽô�.
	//���� �� �迭�� ������ len���� ª���� �������� 0�� ä��ô�.
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
		//i�� ���� �۾��Ұ̴ϴ�.
		int temp[101]{};

		//i�� ���� �󵵼��� ���ô�
		int bignum = 1;
		for (int k = 0; k < row; k++) {
			temp[a[k][i]] += 1;
			if (bignum < a[k][i]) bignum = a[k][i];
		}

		//(����, �󵵼�)�������� v[i]�� �������ݽô�.
		for (int k = 1; k <= bignum; k++) {
			if (temp[k] != 0) {
				v[i].push_back(make_pair(k, temp[k]));
			}
		}
		//���� �� �迭�� ã������ len�� ������ݽô�.
		if (len < v[i].size() * 2) len = v[i].size() * 2;

		sort(v[i].begin(), v[i].end(), cmp);
	}

	if (len > 100) len = 100;
	//���� v�� ��� ������ ���ڵ��� ������ a�� �������ݽô�.
	//���� �� �迭�� ������ len���� ª���� �������� 0�� ä��ô�.
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