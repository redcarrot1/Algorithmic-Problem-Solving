#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> mid;
string map[101];
char a[101][101];
int h, w;

void find(int i) {
	int y, x, cnt;
	tie(y, x, cnt) = mid[i];
	cnt = 1;
	while (1) {
		if (x + cnt > w || x - cnt < 1  || y + cnt > h || y - cnt < 1) break;

		if (map[y][x + cnt] == '*' && map[y][x - cnt] == '*' && map[y + cnt][x] == '*' && map[y - cnt][x] == '*') cnt += 1;
		else break;
	}
	
	mid[i] = make_tuple(y, x, cnt-1);
}

void update(int i) {
	int y, x, s;
	tie(y, x, s) = mid[i];

	a[y][x] = '*';
	for (int i = 1; i <= s; i++) {
		a[y + i][x] = '*';
		a[y - i][x] = '*';
		a[y][x + i] = '*';
		a[y][x - i] = '*';
	}
}

void setMap() {
	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		for (int k = 1; k <= w; k++) {
			a[i][k] = '.';
		}
	}
	string s = ".";
	for (int i = 1; i <= h; i++) {
		cin >> map[i];
		map[i].insert(0, s);

		if (i == 1||i==2) continue;

		for (int k = 2; k < w; k++) {
			if (map[i-1][k] == '*') {
				if (map[i][k] == '*' && map[i-2][k] == '*' && map[i-1][k - 1] == '*' && map[i-1][k + 1] == '*') {
					mid.push_back(make_tuple(i-1, k, 0));
				}
			}
		}

	}
}

int main() {
	setMap();

	for (int i = 0; i < mid.size(); i++) {
		find(i);
		update(i);
	}

	for (int i = 1; i <= h; i++) {
		for (int k = 1; k <= w; k++) {
			if (map[i][k] != a[i][k]) {
				cout << "-1";
				return 0;
			}
		}
	}

	cout << mid.size() << "\n";
	for (int i = 0; i < mid.size(); i++) {
		int y, x, s;
		tie(y, x, s) = mid[i];
		cout << y << " " << x << " " << s << "\n";
	}
}