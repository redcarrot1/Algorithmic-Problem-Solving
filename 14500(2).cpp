#include <iostream>
using namespace std;

int n, m; //n세로 m가로
int a[500][500];
int ans = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int check[500][500];

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}

	
	for (int i = 0; i < 4; i++) {
		int cx = x + dx[i];
		int cy = y + dy[i];
	    if (0 > cx || cx >= m || 0 > cy || cy >= n) continue;
		if (check[cy][cx]) continue;
        else {
            check[cy][cx] = 1;
            go(cx, cy, sum + a[cy][cx], cnt + 1);
            check[cy][cx] = 0;
        }
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
		}
	}
	
    for (int i = 0; i < n; i++) { //세로관련 i, n
        for (int j = 0; j < m; j++) { //가로관련 j, m
            go(j, i, 0, 0);

            if (j + 2 < m) {
                int temp = a[i][j] + a[i][j + 1] + a[i][j + 2];
                if (i - 1 >= 0) {
                    int temp2 = temp + a[i - 1][j + 1];
                    if (ans < temp2) ans = temp2;
                }
                if (i + 1 < n) {
                    int temp2 = temp + a[i + 1][j + 1];
                    if (ans < temp2) ans = temp2;
                }
            }
            if (i + 2 < n) {
                int temp = a[i][j] + a[i + 1][j] + a[i + 2][j];
                if (j + 1 < m) {
                    int temp2 = temp + a[i + 1][j + 1];
                    if (ans < temp2) ans = temp2;
                }
                if (j - 1 >= 0) {
                    int temp2 = temp + a[i + 1][j - 1];
                    if (ans < temp2) ans = temp2;
                }
            }
        }
    }
    cout << ans << '\n';


}