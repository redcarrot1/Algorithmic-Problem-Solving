#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int check[20001][2];

int main() {
	int t;
	cin >> t;

	while (t--) {
		vector<vector<int>> v(20001);
		for (int i = 0; i < 20001; i++) {
			check[i][0] = -1;
		}
		int n, e;
		cin >> n >> e;
		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		int flag = 0;
		queue<pair<int, int>> q;

		for (int i = 1; i <= n; i++) {
			if (check[i][0] != -1) continue;

			q.push(make_pair(i, -1));
			check[i][0] = 0;
			check[i][1] = -1;
			//°Å¸® Â¦¼ö: -1, °Å¸® È¦¼ö:1

			while (!q.empty()) {
				if (flag == 1) break;
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < v[x].size(); i++) {
					int nx = v[x][i];
					if (check[nx][0] != -1) {
						if (check[nx][1] == y) {
							cout << "NO\n";
							flag = 1;
							break;
						}
					}
					else {
						check[nx][0] = check[x][0] + 1;
						check[nx][1] = -1 * check[x][1];
						q.push(make_pair(nx, y * -1));
					}
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) {
			cout << "YES\n";
		}
	}
}