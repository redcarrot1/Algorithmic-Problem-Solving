#include <iostream>
#include <queue>
using namespace std;

int n[101];
int visit[101];

int main() {
	int b, m;
	cin >> b >> m;
	for (int i = 0; i < 101; i++) {
		n[i] = i;
	}

	int pre, pro;
	for (int i = 0; i < b; i++) {
		cin >> pre >> pro;
		n[pre] = pro;
	}
	for (int i = 0; i < m; i++) {
		cin >> pre >> pro;
		n[pre] = pro;
	}

	queue<int> q;
	q.push(1);
	visit[1] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == 100) break;
		for (int i = 1; i <= 6; i++) {
			int cx = x + i;
			cx = n[cx];
			if (visit[cx] !=0) continue;
			visit[cx] = visit[x] + 1;
			q.push(cx);
		}
	}
	cout << visit[100]-1;
}