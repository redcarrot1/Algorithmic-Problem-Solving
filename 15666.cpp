#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, r;
vector<int> a;

void go(int cnt, int k, string str) {
	if (k > r || cnt >= a.size()) return;
	if (k == r) { cout << str << "\n"; return;  }

	//cnt번 숫자를 선택
	go(cnt, k + 1, str + to_string(a[cnt]) + " ");

	//cnt번 숫자를 선택안함
	go(cnt + 1, k, str);
}

int main() {
	cin >> n >> r;
	int k;
	set<int>t;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (t.count(k) == 0) {
			t.insert(k);
			a.push_back(k);
		}
	}
	sort(a.begin(), a.end());
	string s = "";
	go(0, 0, s);
}