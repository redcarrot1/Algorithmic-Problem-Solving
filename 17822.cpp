#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
������ �Ʒ��� ���� ������� �� T�� ȸ����Ű���� �Ѵ�.
������ ȸ�� ����� �̸� ������ �ְ�, i��° ȸ���Ҷ� ����ϴ� ������ xi, di, ki�̴�.

��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ����Ų��.
di�� 0�� ���� �ð� ����, 1�� ���� �ݽð� �����̴�.
���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
�׷��� ���� �ִ� ��쿡�� ���ǿ��� �����ϸ鼭 ���� ���� ��� �����.
���� ��쿡�� ���ǿ� ���� ���� ����� ���ϰ�, ��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�.
������ T�� ȸ����Ų �� ���ǿ� ���� ���� ���� ���غ���.
*/

int n, m, T;
vector<vector<int>> a;
int t[51][3]; //xi, di, ki
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1,0,0 };

void rotation(int x, int d, int k) {
	//x�� ������ d�������� k�� ������
	if (d == 0) {
		rotate(a[x].rbegin(), a[x].rbegin() + k, a[x].rend() - 1);
	}
	if (d == 1) {
		rotate(a[x].begin() + 1, a[x].begin() + 1 + k, a[x].end());
	}
}

void insertData() {
	cin >> n >> m >> T;

	for (int i = 0; i < n + 1; i++) {
		vector<int> element(m + 1);
		a.push_back(element);
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cin >> a[i][k];
		}
	}

	for (int i = 0; i < T; i++) {
		cin >> t[i][0] >> t[i][1] >> t[i][2];
	}
}

int find(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny <= 0 || ny > n) continue;

		if (nx == 0) {
			nx = m;
		}
		else if (nx == m + 1) {
			nx = 1;
		}

		if (a[y][x] == a[ny][nx]) {
			return 1;
		}
	}
	return 0;
}

int bfs() {
	queue<pair<int, int>> q;
	int flag = 0;
	bool check[51][51]{}; //0:no, 1:yes
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (a[i][k] == -1) continue;
			//������ �˻�
			if (k == m) {
				if (a[i][1] != -1) {
					if (a[i][k] == a[i][1]) {
						check[i][k] = true;
						check[i][1] = true;
					}
				}
			}
			else {
				if (a[i][k + 1] != -1) {
					if (a[i][k] == a[i][k + 1]) {
						check[i][k] = true;
						check[i][k + 1] = true;
					}
				}
			}

			//�Ʒ� �˻�
			if (i != n) {
				if (a[i + 1][k] != -1) {
					if (a[i][k] == a[i + 1][k]) {
						check[i][k] = true;
						check[i + 1][k] = true;
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (check[i][k] == true) {
				a[i][k] = -1;
				flag = 1;
			}
		}
	}

	return flag;
}

void print() {
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cout << a[i][k] << " ";
		}
		cout << '\n';
	}
}
int main() {
	insertData();
	int count = 0;
	while (count < T) {
		for (int i = 1; i <= n; i++) {
			if (i % t[count][0] == 0) {
				rotation(i, t[count][1], t[count][2]);
			}
		}
		//cout << "\n===========" << count << "rotation=======\n";
		//print();
		int result = bfs();
		if (result == 0) {
			double sum = 0;
			double co = 0;
			for (int i = 1; i <= n; i++) {
				for (int k = 1; k <= m; k++) {
					if (a[i][k] == -1) continue;
					sum += a[i][k];
					co += 1;
				}
			}
			if (co == 0) {
				cout << "0";
				return 0;
			}
			double avg = sum / co;
			//cout << "\n======" << sum<<" / "<<co << " :" <<avg << "========\n";
			for (int i = 1; i <= n; i++) {
				for (int k = 1; k <= m; k++) {
					if (a[i][k] == -1) continue;
					if (avg - a[i][k] > 0) {
						a[i][k] += 1;
					}
					else if (avg - a[i][k] < 0) {
						a[i][k] -= 1;
					}
				}
			}
		}

		//cout << "\n===========" << count << "=======\n";
		//print();
		count += 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (a[i][k] == -1) continue;
			ans += a[i][k];
		}
	}
	cout << ans;
}