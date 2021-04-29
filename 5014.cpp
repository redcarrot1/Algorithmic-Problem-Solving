#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int check[1000001];

int main() {
	cin >> f >> s >> g >> u >> d;
	queue<int> q;

	q.push(s);
	check[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == g) {
			cout << check[g]-1;
			return 0;
		}

		if (1 <= x + u && x + u <= f) {
			if (check[x + u] == 0) {
				q.push(x + u);
				check[x + u] = check[x] + 1;
			}
		}
		if (1 <= x - d && x - d <= f) {
			if (check[x - d] == 0) {
				q.push(x - d);
				check[x - d] = check[x] + 1;
			}
		}
	}
	cout << "use the stairs";
}