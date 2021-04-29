#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	vector<long long>v;
	int n;
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}

	int f = 0, b = v.size() - 1;
	int ansf=f, ansb=b;
	long long ans = 2000000000;
	while (1) {
		if (f == b) break;
		long long k = v[f] + v[b];

		if (abs(ans) > abs(k)) {
			ans = k;
			ansf = f; ansb = b;
		}

		if (ans == 0) break;
		if (k > 0) b -= 1;
		else if (k < 0) f += 1;
	}
	cout << v[ansf] << " " << v[ansb];
}