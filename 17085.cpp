#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<pair<int, int>> mid;

int h, w;
int find(int y1, int x1, int y2, int x2, vector<vector<int>> a) {
	int m = 1;

	for (int size1 = 0; size1 < 9; size1++) {
		int temp = 0;
		if (y1 + size1 >= h || y1 - size1 < 0 || x1 + size1 >= w || x1 - size1 < 0) break;
		if (a[y1 + size1][x1] != 1 || a[y1 - size1][x1] != 1 || a[y1][x1 + size1] != 1 || a[y1][x1 - size1] != 1) break;
		a[y1 + size1][x1] = a[y1 - size1][x1] = a[y1][x1 + size1] = a[y1][x1 - size1] = 0;

		for (int size2 = 1; size2 < 9; size2++) {
			if (y2 + size2 >= h || y2 - size2 < 0 || x2 + size2 >= w || x2 - size2 < 0) break;
			if (a[y2 + size2][x2] != 1 || a[y2 - size2][x2] != 1 || a[y2][x2 + size2] != 1 || a[y2][x2 - size2] != 1) break;
			temp = size2;
		}
		m = max(m, (4 * temp + 1) * (4 * size1 + 1));
	}
	return m;
}

void setMap(vector<vector<int>>& map) {
	cin >> h >> w;
	char c;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cin >> c;
			if (c == '#') map[i][k] = 1;
			else map[i][k] = 0;
		}
	}

	for (int i = 1; i < h - 1; i++) {
		for (int k = 1; k < w - 1; k++) {
			if (map[i][k] == 1) {
				if (map[i - 1][k] == 1 && map[i + 1][k] == 1 && map[i][k - 1] == 1 && map[i][k + 1] == 1) {
					mid.push_back(make_pair(i, k));
				}
			}
		}
	}
}

int main() {
	vector<vector<int>> map(16, vector<int>(16));
	setMap(map);
	if (mid.size() == 0) {
		cout << "1";
		return 0;
	}

	if (mid.size() == 1) {
		cout << find(mid[0].first, mid[0].second, 0, 0, map);
		return 0;
	}


	int ans = 0;
	vector<bool> temp(mid.size());
	for (int i = 0; i < 2; i++) temp[i] = true;

	do {
		int x1 = -1, x2 = -1, y1, y2;
		for (int i = 0; i < mid.size(); ++i) {
			if (temp[i]) {
				if (x1 == -1) {
					tie(y1, x1) = mid[i];
				}
				else if (x1 != -1) {
					tie(y2, x2) = mid[i];
					break;
				}
			}
		}
		int k = find(y1, x1, y2, x2, map);
		if (ans < k) ans = k;
	} while (prev_permutation(temp.begin(), temp.end()));
	cout << ans;
}