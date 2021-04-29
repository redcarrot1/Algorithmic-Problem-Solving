#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> >map;
int Size, mixum = 0;
void insertData() {
	char c;
	scanf("%d", &Size);
	for (int i = 0; i < Size; i++) {
		vector<int> element(Size);
		map.push_back(element);
	}

	scanf("%1c", &c);
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			scanf("%1c", &c);
			map[i][j] = c;
		}
		scanf("%1c", &c);
	}
}

void check(int start_row, int end_row, int start_col, int end_col) {
	int n = Size;
	int ans = 1;
	for (int i = start_row; i <= end_row; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) {
				cnt += 1;
			}
			else {
				cnt = 1;
			}
			if (mixum < cnt) mixum = cnt;
		}
	}
	for (int i = start_col; i <= end_col; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[j][i] == map[j - 1][i]) {
				cnt += 1;
			}
			else {
				cnt = 1;
			}
			if (mixum < cnt) mixum = cnt;
		}
	}
}

void change() {
	for (int i = 0; i < Size; i++) {
		for (int k = 0; k < Size; k++) {
			if (k < Size - 1) {
				swap(map[i][k], map[i][k + 1]);
				check(i, i, k, k + 1);
				swap(map[i][k + 1], map[i][k]);
			}
			if (i < Size - 1) {
				swap(map[i + 1][k], map[i][k]);
				check(i, i + 1, k, k);
				swap(map[i][k], map[i + 1][k]);
			}
		}
	}
}

int main() {
	insertData();
	change();
	printf("%d", mixum);
}