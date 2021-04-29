#include <iostream>
using namespace std;


int n, s, m, d[101][1001], a[101];

int main() {
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}

	d[0][s] = 1;
	//d[i][j]= i번째 곡을 연주할 때, 볼륨 j로 연주 가능 1, 불가능 0
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (d[i - 1][j] == 1) {
				if (j + a[i] <= m) {
					//cout << i<<"번째 곡은 " << j + a[i] << "볼륨으로 연주 가능\n";
					d[i][j + a[i]] = 1;
				}
				if (j - a[i] >= 0) {
					//cout << i << "번째 곡은 " << j - a[i] << "볼륨으로 연주 가능\n";
					d[i][j - a[i]] = 1;
				}
			}

		}

	}
	for (int i = m; i >= 0; i--) {
		if (d[n][i] == 1) {
			cout << i;
			return 0;
		}
		if (i == 0) cout << "-1";
	}
}
