#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> a;
int ans = 0;

void go(int w) {
	if (a.size() == 2) {
		if (ans < w) ans = w;
		return;
	}

	for (int i = 1; i < a.size() - 1; i++) {
		int k = a[i];
		int nw = a[i - 1] * a[i + 1]+w;
		a.erase(a.begin() + i);
		go(nw);
		a.insert(a.begin()+i, k);
	}
}


int main() {
	cin >> n;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}
	go(0);
	cout << ans;
}