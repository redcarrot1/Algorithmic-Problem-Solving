#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int a[1000][1000];
int check[1000][1000][11][2];
int mo[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };

int main() {
	cin >> n >> m >> k; //세로 가로
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1d", &a[i][k]);
		}
	}

	queue<tuple<int, int, int, int>> q;

	q.push(make_tuple(0, 0, 0, 0));
	check[0][0][0][0] = 1;

	while (!q.empty()) {
		int y, x, z, day;
		tie(y, x, z, day) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + mo[i][0];
			int nx = x + mo[i][1];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			//낮일때
			if (day == 0) {
				if (a[ny][nx] == 0 && check[ny][nx][z][day + 1] == 0) { //벽이 아니고 아직 방문 안했으면
					check[ny][nx][z][day + 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z, day + 1));
				}
				if (z < k && a[ny][nx] == 1 && check[ny][nx][z + 1][day + 1] == 0) { //벽이고 아직 방문 안했으면&& 벽 부신 횟수0 -> 벽 부시기
					check[ny][nx][z + 1][day + 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z + 1, day + 1));
				}
				//낮일땐 가만히 있을 필요가 없다. 벽 부실 수 있는 기회인데 굳이 가만히 있을 이유가 없다.
			}

			//밤일때
			else if (day == 1) {
				if (a[ny][nx] == 0 && check[ny][nx][z][day - 1] == 0) { //벽이 아니고 아직 방문 안했으면
					check[ny][nx][z][day - 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z, day - 1));
				}

				if (check[y][x][z][day - 1] == 0) { //가만히 있는 경우
					check[y][x][z][day - 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(y, x, z, day - 1));
				}
			}
		}
	}

	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		for (int k = 0; k < 2; k++) {
			if (check[n - 1][m - 1][i][k] == 0) continue;
			if (ans > check[n - 1][m - 1][i][k]) ans = check[n - 1][m - 1][i][k];
		}
	}

	if (ans == 2147483647) cout << "-1";
	else cout << ans;
}