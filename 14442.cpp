#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int a[1000][1000];
int check[1000][1000][11];
int mo[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };

int main() {
	cin >> n >> m >> k; //세로 가로
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1d", &a[i][k]);
		}
	}

	queue<tuple<int, int, int>> q;

	q.push(make_tuple(0, 0, 0));
	check[0][0][0] = 1;

	while (!q.empty()) {
		int y, x, z;
		tie(y, x, z) = q.front();
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = y + mo[i][0];
			int ny = x + mo[i][1];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (a[nx][ny] == 0 && check[nx][ny][z] == 0) { //벽이 아니고 아직 방문 안했으면
				check[nx][ny][z] = check[y][x][z] + 1;
				q.push(make_tuple(nx, ny, z));
			}
			if (z < k && a[nx][ny] == 1 && check[nx][ny][z + 1] == 0) { //벽이고 아직 방문 안했으면&& 벽 부신 횟수0 -> 벽 부시기
				check[nx][ny][z + 1] = check[y][x][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}


	int ans = 2147483647;
	for (int i = 0; i <= k; i++) {
		if (check[n - 1][m - 1][i] == 0) continue;
		if (ans > check[n - 1][m - 1][i]) ans = check[n - 1][m - 1][i];
	}

	if (ans == 2147483647) cout << "-1";
	else cout << ans;
}