#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[200000];
int check[200000];
int goal;

void bfs(int x) {
	queue<int> q;
	check[x] = 1;

	q.push(x);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i =0; i < 3; i++) {
			int cx;
			if (i == 0 && x > 0) cx = x - 1;
			else if (i == 1 && x <= 100000) cx = x + 1;
			else if (i == 2 && x <= 50000) cx = x * 2;
			
			if (check[cx] == 0) {
				check[cx] = check[x] + 1;
				if (cx == goal) {
					cout << check[cx] - 1 << '\n';
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
		cout << "0";
		return 0;
	}
	bfs(t);
}