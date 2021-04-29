#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int ans = 99999999;

void go(int d, int opnum, int cnt, int pre) {
	//v[cnt-1] ~ v[cnt]의 관계
	if (cnt == v.size()) {
		ans = min(opnum, ans);
		return;
	}

	if (v[cnt] - 1 - pre == d) go(d, opnum + 1, cnt + 1, v[cnt] - 1);
	else if (v[cnt] + 1 - pre == d) go(d, opnum + 1, cnt + 1, v[cnt] + 1);
	else if (v[cnt] - pre == d) go(d, opnum, cnt + 1, v[cnt]);
	else return;
}

int main() {
	cin >> n;
	int k;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	while (n--) {
		cin >> k;
		v.push_back(k);
	}

	//가능한 공차
	int p1 = v[1] - v[0];
	int p2 = v[1] - v[0]+1;
	int p3 = v[1] - v[0]-1;
	int p4 = v[1] - v[0]+2;
	int p5 = v[1] - v[0]-2;
	go(p1, 0, 1, v[0]);
	go(p1, 1, 1, v[0]-1);
	go(p1, 1, 1, v[0]+1);
	
	go(p2, 0, 1, v[0]);
	go(p2, 1, 1, v[0]-1);
	
	go(p3, 0, 1, v[0]);
	go(p3, 1, 1, v[0]+1);

	go(p4, 1, 1, v[0]-1);
	go(p5, 1, 1, v[0]+1);

	if (ans == 99999999) cout << "-1";
	else cout << ans;
}