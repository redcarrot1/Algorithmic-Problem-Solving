#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[300][300];

int dx[] = { -2, -1, 1, 2, 2, 1 ,-1, -2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

void bfs(int l, int iy, int ix, int gy, int gx) {
	queue<pair<int, int>> q;
	vector<vector<int> > check(l, vector<int>(l, 0));

	check[iy][ix] = 1;
	q.push(make_pair(iy, ix));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int cy = y + dy[i];
			int cx = x + dx[i];
			if (0 <= cx && cx < l && 0 <= cy && cy < l) {
				if (check[cy][cx] == 0) {
					check[cy][cx] = check[y][x] + 1;
					if (cy == gy && cx == gx) {
						cout << check[gy][gx] - 1 << '\n';
						return;
					}
					q.push(make_pair(cy, cx));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int l, ix, iy, gx, gy;
		cin >> l >> iy >> ix >> gy >> gx;
		if (iy == gy && ix == gx) {
			cout << "0\n"; continue;
		}
		bfs(l, iy, ix, gy, gx);
	}
}