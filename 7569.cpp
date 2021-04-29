#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;
int a[101][101][101];
int check[101][101][101];
int m, n, h;
int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> m >> n >> h; //가로 세로 높이
	queue < tuple<int, int, int>> q;

	for (int i = 0; i < h; i++) {
		for (int z = 0; z < n; z++) {
			for (int q = 0; q < m; q++) {
				check[z][q][i] = -1;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int z = 0; z < n; z++) {
			for (int k = 0; k < m; k++) {
				cin >> a[z][k][i];
				if (a[z][k][i] == 1) {
					q.push(make_tuple(z, k, i));
					check[z][k][i] = 0;
				}
			}
		}
	}

	while (!q.empty()) {
		int x, y, z;
		tie(y, x, z) = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dh[i];

			if (0 > nx || nx >= m || 0 > ny || ny >= n || 0 > nz || nz >= h) continue;

			if (a[ny][nx][nz]==-1 || check[ny][nx][nz]!=-1) continue;
			
			q.push(make_tuple(ny, nx, nz));
			check[ny][nx][nz] = check[y][x][z] + 1;

		}
	}

	int ans = -1;
	for (int i = 0; i < h; i++) {
		for (int z = 0; z < n; z++) {
			for (int q = 0; q < m; q++) {
				if (check[z][q][i] == -1 && a[z][q][i] == 0) {
					cout << "-1";
					return 0;
				}
				if(ans<check[z][q][i]) ans=check[z][q][i];
			}
		}
	}
	cout << ans;

}