#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int map[200000];
int check[200000];
int goal;
int from[200000];

void bfs(int x) {
	int n = x;
	queue<int> q;
	check[x] = 1;

	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < 3; i++) {
			int cx;
			if (i == 0 && x > 0) cx = x - 1;
			else if (i == 1 && x <= 100000) cx = x + 1;
			else if (i == 2 && x <= 50000) cx = x * 2;
			else cx = x;

			if (check[cx] == 0) {
				from[cx] = x;
				check[cx] = check[x] + 1;
				if (cx == goal) {
					cout << check[cx] - 1 << '\n';
					stack<int>arr;
					for (int i = cx; i!=n; i=from[i]) {
						arr.push(i);
					}
					arr.push(n);

					while (!arr.empty()) {
						cout << arr.top() << ' ';
						arr.pop();
					}
					return;
				}
				q.push(cx);
			}
		}
	}
}

int main() {
	int t;
	cin >> t >> goal;
	if (t == goal) {
		cout << "0\n";
		cout << t;
		return 0;
	}
	bfs(t);
}