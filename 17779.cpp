#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int a[21][21];
int n;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void bfs(vector<vector<int>>& d, int y, int x, int g) {
	d[y][x] = g;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (0 < nx && nx <= n && 0 < ny && ny <= n) {
				if (d[ny][nx] == 0) {
					d[ny][nx] = g;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
}

int update(int x, int y, int d1, int d2) {
	vector<vector<int>> d(n + 1, vector<int>(n + 1));
	//경계선만 먼저 할당 후
	//bfs를 통해 나머지 구간 할당하기

	//5번 선거구
	d[y][x] = 5;
	for (int i = 1; i <= d1; i++) {
		d[y - i][x + i] = 5;
	}
	for (int i = 1; i <= d2; i++) {
		d[y + i][x + i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		d[y - d1 + i][x + d1 + i] = 5;
	}
	for (int i = 0; i <= d1; i++) {
		d[y + d2 - i][x + d2 + i] = 5;
	}

	//1번 선거구
	if (y - d1 - 1 >= 0) {
		for (int i = 1; i < y - d1; i++) {
			d[i][x + d1] = 1;
		}
	}

	//2번 선거구
	if (x + d2 + d1 + 1 <= n) {
		for (int i = x + d2 + d1 + 1; i <= n; i++) {
			d[y + d2 - d1][i] = 2;
		}
	}

	//3번 선거구
	if (x > 1) {
		for (int i = 1; i < x; i++) {
			d[y][i] = 3;
		}
	}

	//4번 선거구
	if (y + d2 + 1 <= n) {
		for (int i = y + d2 + 1; i <= n; i++) {
			d[i][x + d2] = 4;
		}
	}
	
	bfs(d, 1, 1, 1);
	bfs(d, 1, n, 2);
	bfs(d, n, 1, 3);
	bfs(d, n, n, 4);


	int co[6]{};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == 0) d[i][j] = 5;
			co[d[i][j]] += a[i][j];
		}
	}
	return (*max_element(co + 1, co + 6) - *min_element(co + 1, co + 6));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			cin >> a[i][k];
		}
	}

	//x y >=2, <n
	//1<=d1 d2
	//d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N)
	int ans = 10000000;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) {
						int k = update(x, y, d1, d2);
						if (ans > k) ans = k;
					}
				}
			}
		}
	}
	cout << ans;
}