#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
int n, r;
vector<int> a;
int b[8]{};
void go(int cnt, int chos) {
	if (chos > r) return;
	if (cnt == a.size()) {
		if (chos == r) {
			for (int i = 0; i < a.size(); i++) {
				for (int k = 0; k < b[i]; k++) {
					cout << a[i] << " ";
				}
			}
			cout << "\n";
		}
		return;
	}
	
	for (int i = 0; i <= r - chos; i++) {
		b[cnt] += i;
		go(cnt + 1, chos + i);
		b[cnt] -= i;
	}

}
bool compare(int a, int b) {
	return a > b;
}

void insertData() {
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
}

int main() {
	insertData();
	sort(a.begin(), a.end(), compare);
	go(0, 0);
}