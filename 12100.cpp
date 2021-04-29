#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > map;
int n, ans = 0;
void setData() {
	int q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int> element(n);
		map.push_back(element);
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> q;
			map[i][k] = q;
		}
	}
}

vector<vector<int>> up(vector<vector<int>>& a) {
	vector<int> temp[20];

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[k][i] == 0) continue;
			temp[i].push_back(a[k][i]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (temp[i].size() == 0) continue;
		for (int k = 0; k < temp[i].size() - 1; k++) {
			if (temp[i][k] == temp[i][k + 1]) {
				temp[i][k] += temp[i][k];
				temp[i].erase(temp[i].begin() + k + 1);
			}
		}
	}

	vector<vector<int> > b(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < temp[i].size(); k++) {
			b[k][i] = temp[i][k];
		}
		for (int k = temp[i].size(); k < n; k++) {
			b[k][i] = 0;
		}
	}

	return b;
}

vector<vector<int>> down(vector<vector<int>>& a) {
	vector<int> temp[20];

	for (int i = 0; i < n; i++) {
		for (int k = n - 1; k >= 0; k--) {
			if (a[k][i] == 0) continue;
			temp[i].push_back(a[k][i]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (temp[i].size() == 0) continue;
		for (int k = 0; k < temp[i].size() - 1; k++) {
			if (temp[i][k] == temp[i][k + 1]) {
				temp[i][k] += temp[i][k];
				temp[i].erase(temp[i].begin() + k + 1);
			}
		}
	}

	vector<vector<int> > b(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		int cnt = n - 1;
		for (int k : temp[i]) {
			b[cnt][i] = k;
			cnt -= 1;
		}
		for (int k = cnt; k >= 0; k--) {
			b[k][i] = 0;
		}
	}

	return b;
}

vector<vector<int>> left(vector<vector<int>>& a) {
	vector<int> temp[20];

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] == 0) continue;
			temp[i].push_back(a[i][k]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (temp[i].size() == 0) continue;
		for (int k = 0; k < temp[i].size() - 1; k++) {
			if (temp[i][k] == temp[i][k + 1]) {
				temp[i][k] += temp[i][k];
				temp[i].erase(temp[i].begin() + k + 1);
			}
		}
	}

	vector<vector<int> > b(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < temp[i].size(); k++) {
			b[i][k] = temp[i][k];
		}
		for (int k = temp[i].size(); k < n; k++) {
			b[i][k] = 0;
		}
	}

	return b;
}

vector<vector<int>> right(vector<vector<int>>& a) {
	vector<int> temp[20];

	for (int i = 0; i < n; i++) {
		for (int k = n - 1; k >= 0; k--) {
			if (a[i][k] == 0) continue;
			temp[i].push_back(a[i][k]);
		}
	}

	for (int i = 0; i < n; i++) {
		if (temp[i].size() == 0) continue;
		for (int k = 0; k < temp[i].size() - 1; k++) {
			if (temp[i][k] == temp[i][k + 1]) {
				temp[i][k] += temp[i][k];
				temp[i].erase(temp[i].begin() + k + 1);
			}
		}
	}

	vector<vector<int> > b(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		int cnt = n - 1;
		for (int k : temp[i]) {
			b[i][cnt] = k;
			cnt -= 1;
		}
		for (int k = cnt; k >= 0; k--) {
			b[i][k] = 0;
		}
	}

	return b;
}

void findMax(vector<vector<int>>& a) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (a[i][k] > ans) ans = a[i][k];
		}
	}
}

void go(int cnt, vector<vector<int>> a) {
	if (cnt == 5) {
		findMax(a);
		return;
	}
	go(cnt + 1, up(a));
	go(cnt + 1, down(a));
	go(cnt + 1, left(a));
	go(cnt + 1, right(a));
}

void print(vector<vector<int>>& a) {
	cout << "\n===============\n";
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cout << a[i][k] << " ";
		}
		cout << '\n';
	}
	cout << "\n===============\n";
}

int main() {
	setData();
	/*vector<vector<int>> u=up(map);
	print(u);
	vector<vector<int>> d = down(map);
	print(d);
	vector<vector<int>> l = left(map);
	print(l);
	vector<vector<int>> r = right(map);
	print(r);*/
	go(0, map);
	cout << ans;
}