#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int a[50][50];
vector<pair<int, int>> h;
vector<pair<int, int>> ch;
int ans = 99999999;
void setData() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> a[i][k];
			if (a[i][k] == 1) h.push_back(make_pair(i, k));
			else if (a[i][k] == 2) ch.push_back(make_pair(i, k));
		}
	}
}

void bfs(set<int>& al) {
	int dis = 0;
	for (int i = 0; i < h.size(); i++) {
		int temp = 9999999;
		for (int k = 0; k < ch.size(); k++) {
			if (al.find(k) != al.end()) {
				temp = min(temp, abs(h[i].first - ch[k].first) + abs(h[i].second - ch[k].second));
			}
		}
		dis += temp;
	}
	ans = min(dis, ans);
}

int main() {
	setData();

	vector<bool> temp(ch.size());
	for (int i = 0; i < m; i++) temp[i] = true;

	do {
		set<int> al;
		for (int i = 0; i < ch.size(); ++i) {
			if (temp[i]) {
				//i번 가게는 살아남는다.
				al.insert(i);
			}
		}
		bfs(al);
	} while (prev_permutation(temp.begin(), temp.end()));

	cout << ans;
}