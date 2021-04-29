#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[51][51];
vector < tuple<int, int, int>> op;
int h, w;

void ratation(int r, int c, int s, int b[51][51]) {
	//(r-s, c-s) (r-s, c+s) (r+s, c+s) (r+s, c-s)
	vector<int> temp;

	for (int i = c - s; i < c + s; i++) {
		temp.push_back(b[r - s][i]);
	}

	for (int i = r - s; i < r + s; i++) {
		temp.push_back(b[i][c + s]);
	}

	for (int i = c + s; i > c - s; i--) {
		temp.push_back(b[r + s][i]);
	}

	for (int i = r + s; i > r - s; i--) {
		temp.push_back(b[i][c - s]);
	}

	rotate(temp.rbegin(), temp.rbegin() + 1, temp.rend());

	int k = 0;
	for (int i = c - s; i < c + s; i++) {
		b[r - s][i] = temp[k];
		k += 1;
	}

	for (int i = r - s; i < r + s; i++) {
		b[i][c + s] = temp[k];
		k += 1;
	}

	for (int i = c + s; i > c - s; i--) {
		b[r + s][i] = temp[k];
		k += 1;
	}

	for (int i = r + s; i > r - s; i--) {
		b[i][c - s] = temp[k];
		k += 1;
	}
}

int main() {
	int k, x, y, z;
	cin >> h >> w >> k;

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cin >> a[i][k];
		}
	}

	for (int i = 0; i < k; i++) {
		cin >> y >> x >> z;
		op.push_back(make_tuple(y - 1, x - 1, z));
	}

	sort(op.begin(), op.end());

	int ans = 10000;
	do {
		int b[51][51];
		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				b[i][k] = a[i][k];
			}
		}

		for (int i = 0; i < op.size(); i++) {
			tie(y, x, z) = op[i];

			for (int k = 1; k <= z; k++) {
				ratation(y, x, k, b);
			}
		}

		for (int i = 0; i < h; i++) {
			int temp = 0;
			for (int k = 0; k < w; k++) {
				temp += b[i][k];
			}
			if (ans > temp) ans = temp;
		}
	} while (next_permutation(op.begin(), op.end()));
	cout << ans;
}