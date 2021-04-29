#include <iostream>
#include <algorithm>
using namespace std;

int height[9];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		height[i] = n;
		sum += n;
	}
	sort(height, height + 9);
	int a, b;
	for (int i = 0; i < 8; i++) {
		for (int k = i + 1; k < 9; k++) {
			if (sum - height[i]-height[k] == 100) {
				a = i;
				b = k;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		cout << height[i] << '\n';
	}
		
}