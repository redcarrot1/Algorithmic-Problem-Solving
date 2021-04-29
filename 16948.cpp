#include <iostream>
#include <queue>
using namespace std;

int n;
int a[200][200];
int moving[6][2] = { {-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1},{2, 1} };
int goalx, goaly;

int main() {
	int x, y;
	cin >> n >> x >> y >> goalx >> goaly;
	a[x][y] = 1;
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == goalx && y == goaly) {
			break;
		}

		for (int i = 0; i < 6; i++) {
			int cx = x+moving[i][0];
			int cy = y+moving[i][1];
			if (0 <= cx && cx < n && 0 <= cy && cy < n) {
				if (a[cx][cy] != 0) continue;
				a[cx][cy] = a[x][y] + 1;
				q.push(make_pair(cx, cy));
			}
		}
	}
	
	cout << a[goalx][goaly] - 1;
}