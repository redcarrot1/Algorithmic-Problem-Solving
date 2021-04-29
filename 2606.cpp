#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector< vector<int> >v(101);
bool check[101];
int n;

int main() {
	int p;
	cin >> n >> p;

	int a, b;
	for (int i = 0; i < p; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	check[1] = true;
	int ans = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];
			if (check[nx] == true) continue;

			ans += 1;
			q.push(nx);
			check[nx] = true;
		}
	}
	cout << ans-1;
}