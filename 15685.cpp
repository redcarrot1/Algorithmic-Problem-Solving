#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int a[101][101];
vector<int> totalmove[20];

void makeGen(int z, int gen, int k) {
	//z세대를 만들어줌
	if (z == gen + 1) return;
	int s = totalmove[k].size();
	for (int i = s - 1; i >= 0; i--) {
		if (totalmove[k][i] == 0) totalmove[k].push_back(1);
		else if (totalmove[k][i] == 1) totalmove[k].push_back(2);
		else if (totalmove[k][i] == 2) totalmove[k].push_back(3);
		else if (totalmove[k][i] == 3) totalmove[k].push_back(0);
	}
	makeGen(z + 1, gen, k);
}

void set(int y, int x, int k) {
	a[y][x] = 1;

	for (int i = 0; i < totalmove[k].size(); i++) {
		x = x + dx[totalmove[k][i]];
		y = y + dy[totalmove[k][i]];
		a[y][x] = 1;
	}
}

int main() {
	int n, pointx, pointy, dir, gen;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pointx >> pointy >> dir >> gen;
		totalmove[i].push_back(dir);
		makeGen(1, gen, i);
		set(pointy, pointx, i);
	}

	int ans = 0;
	for (int i = 0; i <= 99; i++) {
		for (int k = 0; k <= 99; k++) {
			if (a[i][k] == 0) continue;
			if (a[i + 1][k] == 1 && a[i][k + 1] == 1 && a[i + 1][k + 1] == 1) ans += 1;
		}
	}
	cout << ans;
}