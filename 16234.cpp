#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, l, r;
int a[51][51];
int d[51][51];
int check[51][51];
int share[51 * 51];

//국경선 오른쪽 2^0, 아래 2^1, 왼쪽 2^2, 위 2^3 ->비트마스크 이용

int make_union() {
	//각 칸이 자신의 오른쪽, 아래쪽을 검사
	//맨 오른줄 또는 맨 아래줄은 검사에 예외설정 넣을것

	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			//오른쪽 검사
			if (k != n - 1) {
				int diff = abs(a[i][k] - a[i][k + 1]);
				if (l <= diff && diff <= r) {
					d[i][k] = d[i][k] | (1 << 0);
					d[i][k + 1] = d[i][k + 1] | (1 << 2);
					flag = 1;
				}
			}

			//아래쪽 검사
			if (i != n - 1) {
				int diff = abs(a[i][k] - a[i + 1][k]);
				if (l <= diff && diff <= r) {
					d[i][k] = d[i][k] | (1 << 1);
					d[i + 1][k] = d[i + 1][k] | (1 << 3);
					flag = 1;
				}
			}
		}
	}

	return flag;
}

void bfs() {
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (check[i][k] == false) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, k));
				check[i][k] = cnt;

				int sum = 0;
				int count = 0;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					sum += a[y][x];
					count += 1;

					for (int j = 0; j < 4; j++) {
						if ((d[y][x] & (1 << j)) == 0) continue;
						int ny, nx;
						if (j == 0) {
							ny = y;
							nx = x + 1;
						}
						else if (j == 1) {
							ny = y + 1;
							nx = x;
						}
						else if (j == 2) {
							ny = y;
							nx = x - 1;
						}
						else if (j == 3) {
							ny = y - 1;
							nx = x;
						}
						if (check[ny][nx] != 0) continue;

						q.push(make_pair(ny, nx));
						check[ny][nx] = cnt;
					}
				}

				share[cnt]= sum/count;
				cnt += 1;
			}
		}
	}
}

void update() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			a[i][k] = share[check[i][k]];
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << a[i][k] << " ";
		}
		cout << "\n";
	}
}

void printcheck() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << check[i][k] << " ";
		}
		cout << "\n";
	}
}

void insertData() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
		}
	}
}

int main() {
	insertData();
	int ans = 0;

	while (1) {
		//cout << "\n========" << ans << "===========\n";
		//printcheck();
		//cout << "==============\n";
		//print();
		memset(d, 0, sizeof(d));
		memset(check, 0, sizeof(check));
		if (make_union() == 0) break;
		bfs();
		update();
		ans += 1;
	}
	cout << ans;
}