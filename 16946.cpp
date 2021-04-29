#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int map[1000][1000];
int check[1000][1000];
int ans[1000][1000];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n, m; // 세로 가로
vector<int>v;

void bfs(int starty, int startx, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(starty, startx));
	check[starty][startx] = cnt;
	int cout = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
			if (check[ny][nx] != 0 || map[ny][nx] != 0) continue;
			check[ny][nx] = cnt;
			q.push(make_pair(ny, nx));
			cout += 1;
		}
	}
	v.push_back(cout);
}

void dupcheck(int group[4]) { //set<int> 말고 배열 사용시, 같은 그룹을 중복해서 더해주는 경우를 없애주기 위해
	for (int i = 0; i < 4; i++) {
		int k = group[i];
		for (int z = 0; z < i; z++) {
			if (k == group[z]) { group[i] = 0; break; }
		}
	}

}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			scanf("%1d", &map[i][k]);
		}
	}
	int group_num = 1;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (check[i][k] == 0 && map[i][k] == 0) {
				bfs(i, k, group_num);
				group_num += 1;
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cout << check[i][k];
		}
		cout << "\n";
	}*/

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == 1) {
				set<int> near;
				for (int q = 0; q < 4; q++) {
					int ny = i + dy[q];
					int nx = k + dx[q];
					if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
					if (check[ny][nx] != 0)  near.insert(check[ny][nx]);
				}
				

				for (int g : near) {
					ans[i][k] += v[g-1];
				}
				ans[i][k] += 1;
				ans[i][k] %= 10;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cout << ans[i][k];
		}
		cout << '\n';
	}
}