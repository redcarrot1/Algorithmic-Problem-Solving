#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[16][16];
int n, m, d;

int ans = 0, total;

//x열 성에서 죽일 수 있는 적의 위치를 리턴. 죽일 수 없는 경우 -1, -1 리턴
pair<int, int> distance(int map[16][16], int x) {
	int shortdis = 99999;
	int leftest = 16;
	int ty=-1, tx=-1;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == 1) {
				int dist = abs(i - (n)) + abs(k - x);
				if (dist > d) continue;

				if (dist < shortdis) {
					shortdis = dist;
					leftest = k;
					ty = i;
					tx = k;
				}
				else if (dist == shortdis) {
					if (leftest > k) {
						leftest = k;
						ty = i;
						tx = k;
					}
				}
			}
		}
	}

	return make_pair(ty, tx);
}

void print(int map[16][16]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cout << map[i][k] << " ";
		}
		cout << "\n";
	}
}

bool check(int map[16][16]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			if (map[i][k] == 1) {
				return false;
			}
		}
	}
	return true;
}

void go(int map[16][16], int x1, int x2, int x3, int pass) {
	if (check(map) == true) {
		//cout << pass<<"\n";
		ans = max(ans, total - pass);
		return;
	}

	int ty1, tx1=-1;
	tie(ty1, tx1) = distance(map, x1);
	
	int ty2, tx2=-1;
	tie(ty2, tx2) = distance(map, x2);

	int ty3, tx3=-1;
	tie(ty3, tx3) = distance(map, x3);

	if(tx1 != -1) map[ty1][tx1] = 0;
	if(tx2 != -1) map[ty2][tx2] = 0;
	if(tx3 != -1) map[ty3][tx3] = 0;

	int p = 0;
	for (int i = n-1; i>=0; i--) {
		for (int k = 0; k < m; k++) {
			if (i == n - 1) {
				if (map[i][k] == 1) {
					map[i][k] = 0;
					p += 1;
				}
			}
			else {
				if (map[i][k] == 1) {
					map[i+1][k] = 1;
					map[i][k] = 0;
				}
			}
		}
	}
	//cout << "======"<<p<<"======\n";
	//print(map);
	//cout << "==============\n";
	go(map, x1, x2, x3, pass + p);
}

int main() {
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
			if (a[i][k] == 1) total += 1;
		}
	}

	vector<bool> temp(m);
	for (int i = 0; i < 3; i++) temp[i] = true;

	do {
		int newmap[16][16];
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				newmap[i][k] = a[i][k];
			}
		}

		int x1 = -1, x2 = -1, x3 = -1;
		for (int i = 0; i < m; ++i) {
			if (temp[i]) {
				if (x1 == -1) x1 = i;
				else if (x2 == -1) x2 = i;
				else if (x3 == -1) x3 = i;
			}
		}
		//cout << x1 << " " << x2 << " " << x3 << " \n\n";
		go(newmap, x1, x2, x3, 0);
	} while (prev_permutation(temp.begin(), temp.end()));

	cout << ans;
}