#include <iostream>
using namespace std;

int map[100001][2];
int d[100001][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	int n = 1;
	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> map[i][0];
		}
		for (int i = 0; i < n; i++) {
			cin >> map[i][1];
		}

		d[0][0] = map[0][0];
		d[0][1] = map[0][1];
		d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(d[i - 1][1], d[i - 1][2]) + map[i][0];
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + map[i][1];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]);
		}
		int ans = max(d[n-1][0], d[n-1][1]);
		cout << ans << '\n';
	}
}