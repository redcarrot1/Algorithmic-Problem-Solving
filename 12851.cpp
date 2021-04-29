#include <iostream>
#include <queue>
using namespace std;

int c, goal;
int a[100001][2];

void setarray() {
	for (int i = 0; i < 100001; i++) {
		a[i][0] = -1;
		a[i][1] = -1;
	}

	a[c][0] = 0;
	a[c][1] = 1;
}

void bfs() {
	int flag = 0;
	int shorttime = 1000001;

	setarray();


	queue<int> q;
	q.push(c);
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (a[x][0] >= shorttime) break;

		if (x == goal && flag == 0) {
			shorttime = a[goal][0];
			flag = 1;
			continue;
		}

		if (x + 1 < 100001) {
			if (a[x + 1][0] == -1 && flag==0) {
				q.push(x + 1);
				a[x + 1][0] = a[x][0] + 1;
				a[x + 1][1] = a[x][1];
			}
			else {
				if (a[x + 1][0] == a[x][0] + 1) {
					a[x + 1][1] += a[x][1];
				}
			}
		}

		if (x - 1 > -1) {
			if (a[x - 1][0] == -1 && flag == 0) {
				q.push(x - 1);
				a[x - 1][0] = a[x][0] + 1;
				a[x - 1][1] = a[x][1];
			}
			else {
				if (a[x - 1][0] == a[x][0] + 1) {
					a[x - 1][1] += a[x][1];
				}
			}
		}

		if (2 * x < 100001 ) {
			if (a[2 * x][0] == -1 && flag == 0) {
				q.push(2 * x);
				a[2 * x][0] = a[x][0] + 1;
				a[2 * x][1] = a[x][1];
			}
			else {
				if (a[2 * x][0] == a[x][0] + 1) {
					a[2 * x][1] += a[x][1];
				}
			}
		}
	}

	/*for (int i = 1; i <= goal+1; i++) {
		cout << i<<": "<<a[i][1] << "\n";
	}*/
	cout << shorttime << "\n" << a[goal][1];
}

int main() {
	cin >> c >> goal;
	bfs();
}