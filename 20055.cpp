#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0, k;

void ratation(vector<int>& durabil, vector<bool>& robot) {
	rotate(durabil.rbegin(), durabil.rbegin() + 1, durabil.rend());
	rotate(robot.rbegin(), robot.rbegin() + 1, robot.rend());
}

void robotMove(vector<int>& durabil, vector<bool>& robot) {
	if (robot[n - 1] == true) robot[n - 1] = false;

	for (int i = n - 2; i >= 0; i--) {
		if (robot[i] == true && durabil[i + 1] > 0 && robot[i + 1] == false) {
			robot[i] = false;
			robot[i + 1] = true;
			durabil[i + 1] -= 1;
		}
	}

	if (robot[n - 1] == true) robot[n - 1] = false;
	if (robot[0] == false && durabil[0] > 0) {
		robot[0] = true;
		durabil[0] -= 1;
	}
}

int check(vector<int>& durabil) {
	int cum = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (durabil[i] == 0) {
			cum += 1;
		}
	}
	return cum;
}

int main() {
	cin >> n >> k;
	vector<int> durabil(2 * n);
	vector<bool> robot(2 * n);

	for (int i = 0; i < 2 * n; i++) {
		cin >> durabil[i];
	}

	int ans = 0;
	while (1) {
		if (check(durabil) >= k) break;
		ratation(durabil, robot);
		robotMove(durabil, robot);
		ans += 1;
	}
	cout << ans;
}