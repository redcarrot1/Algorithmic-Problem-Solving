#include <iostream>
using namespace std;
//https://chanhuiseok.github.io/posts/baek-19/

int n, m;
int a[1025][1025]{};
void insertData() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			a[i + 1][j + 1] = a[i][j + 1] + a[i + 1][j] - a[i][j] + num;
		}
	}
}
int main() {
	insertData();

	int x1, y1, x2, y2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;

		cout << a[y2][x2] - a[y1 - 1][x2] - a[y2][x1 - 1] + a[y1 - 1][x1 - 1] << '\n';
	}
}