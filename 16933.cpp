#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
int a[1000][1000];
int check[1000][1000][11][2];
int mo[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0,-1} };

int main() {
	cin >> n >> m >> k; //���� ����
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

			//���϶�
			if (day == 0) {
				if (a[ny][nx] == 0 && check[ny][nx][z][day + 1] == 0) { //���� �ƴϰ� ���� �湮 ��������
					check[ny][nx][z][day + 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z, day + 1));
				}
				if (z < k && a[ny][nx] == 1 && check[ny][nx][z + 1][day + 1] == 0) { //���̰� ���� �湮 ��������&& �� �ν� Ƚ��0 -> �� �νñ�
					check[ny][nx][z + 1][day + 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z + 1, day + 1));
				}
				//���϶� ������ ���� �ʿ䰡 ����. �� �ν� �� �ִ� ��ȸ�ε� ���� ������ ���� ������ ����.
			}

			//���϶�
			else if (day == 1) {
				if (a[ny][nx] == 0 && check[ny][nx][z][day - 1] == 0) { //���� �ƴϰ� ���� �湮 ��������
					check[ny][nx][z][day - 1] = check[y][x][z][day] + 1;
					q.push(make_tuple(ny, nx, z, day - 1));
				}

				if (check[y][x][z][day - 1] == 0) { //������ �ִ� ���
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