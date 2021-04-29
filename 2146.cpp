#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int a[101][101], n;
int check[101][101];
int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
		}
	}

	//1st. 섬을  그룹별로 찾기
	queue<pair<int, int>> q;
	int cnt = 2;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] == 1) {
				q.push(make_pair(i, k));
				a[i][k] = cnt;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int j = 0; j < 4; j++) {
						int ny = y + dy[j];
						int nx = x + dx[j];
						if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;

						if (a[ny][nx] == 1) {
							a[ny][nx] = cnt;
							q.push(make_pair(ny, nx));
						}
					}
				}

				cnt += 1;
			}
		}
	}
	//cout << "\n========\n";
	//for (int i = 0; i < n; i++) {
	//	for (int k = 0; k < n; k++) {
	//		cout << a[i][k] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n========\n\n";
	
	
	//2nd. 각 섬에서 다른 섬까지의 거리 측정
	int ans = 2999999;
	cnt = 2;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] == cnt) {
				memset(check, -1, sizeof(check));

				q.push(make_pair(i, k));
				check[i][k] = 0;

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int j = 0; j < 4; j++) {
						int ny = y + dy[j];
						int nx = x + dx[j];
						if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;

						if (a[ny][nx] != cnt && a[ny][nx] != 0) {
							if (ans > check[y][x] + 1) {
								ans = check[y][x] + 1;
								//cout << cnt << "번 섬에서 " << a[ny][nx] << "섬으로 가는 최단길이: " << ans << "\n";
							}
							continue;
						}

						if (a[ny][nx] == cnt && check[ny][nx] == -1) {
							check[ny][nx] = 0;
							q.push(make_pair(ny, nx));
						}

						else if (a[ny][nx] == 0) {
							if (check[ny][nx] == -1) {
								check[ny][nx] = check[y][x] + 1;
								q.push(make_pair(ny, nx));
							}
							else if (check[ny][nx] > check[y][x] + 1) {
								check[ny][nx] = check[y][x] + 1;
								q.push(make_pair(ny, nx));
							}
						}
					}
				}
				/*cout << "\n========\n";
				for (int i = 0; i < n; i++) {
					for (int k = 0; k < n; k++) {
						cout << check[i][k] << " ";
					}
					cout << "\n";
				}
				cout << "\n========\n\n";*/
				cnt += 1;

				while (!q.empty()) {
					q.pop();
				}
			}
		}
	}
	cout << ans - 1;
}