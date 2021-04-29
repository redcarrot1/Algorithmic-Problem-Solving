#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int a[1000] = { 0, };
	int b[1000] = { 0, };
	int t, n, m, num;
	vector<int>v;
	vector<int>w;
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		a[i] = num;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		b[i] = num;
	}

	//a로 만들 수 있는 부분합
	for (int i = 0; i < n; i++) {
		int sum = a[i];
		v.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
			v.push_back(sum);
		}
	}


	for (int i = 0; i < m; i++) {
		int sum = b[i];
		w.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			w.push_back(sum);
		}
	}

	sort(w.begin(), w.end());
	long long ans = 0;
	for (auto item : v)
	{
		int diff = t - item;
		auto ub = upper_bound(w.begin(), w.end(), diff);
		auto lb = lower_bound(w.begin(), w.end(), diff);
		ans += (ub - lb);
	}
	cout << ans;
}