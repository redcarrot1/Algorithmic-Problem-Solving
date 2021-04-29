#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
원판을 아래와 같은 방법으로 총 T번 회전시키려고 한다.
원판의 회전 방법은 미리 정해져 있고, i번째 회전할때 사용하는 변수는 xi, di, ki이다.

번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다.
di가 0인 경우는 시계 방향, 1인 경우는 반시계 방향이다.
원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
그러한 수가 있는 경우에는 원판에서 인접하면서 같은 수를 모두 지운다.
없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다.
원판을 T번 회전시킨 후 원판에 적힌 수의 합을 구해보자.
*/

int n, m, T;
vector<vector<int>> a;
int t[51][3]; //xi, di, ki
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1,0,0 };

void rotation(int x, int d, int k) {
	//x번 원판을 d방향으로 k번 돌리자
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
			//오른쪽 검사
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

			//아래 검사
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