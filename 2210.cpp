#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int a[5][5];
set<int> s;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0,0};
void go(int x, int y, int cnt, int sum) {
	if (cnt == 6) {
		s.insert(sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		go(nx, ny, cnt + 1, 10 * sum + a[nx][ny]);
	}

}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			cin >> a[i][k];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < 5; k++) {
			go(i, k, 0, 0);
		}
	}
	cout << s.size();
}