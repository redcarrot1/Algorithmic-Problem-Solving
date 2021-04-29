#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<pair<int, int>> v;

double ans = 2147483647;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

void go() {
	vector<int> k;
	for (int i = 0; i < v.size() / 2; i++)
		k.push_back(0);
	for (int i = 0; i < v.size() / 2; i++)
		k.push_back(1);

	do {
		long long tx = 0, ty = 0;
		double t_result;
		for (int i = 0; i < v.size(); i++) {
			if (k[i] == 0) {
				tx += v[i].first;
				ty += v[i].second;
			}
			else {
				tx -= v[i].first;
				ty -= v[i].second;
			}
		}
		t_result = tx * tx + ty * ty;
		ans = min(ans, sqrt(t_result));
	} while (next_permutation(k.begin(), k.end()));
}

int main() {
	int t, x, y;
	scanf("%d", &t);
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end(), compare);

		go();
		printf("%.7f\n", ans);
		v.clear();
		ans = 2147483647;
	}
}