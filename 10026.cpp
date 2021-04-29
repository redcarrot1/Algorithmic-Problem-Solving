#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

void insertData(char a[100][100], char b[100][100]) {
	scanf("%d", &n);
	char c;
	scanf("%1c", &c);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			scanf("%1c", &c);
			a[i][k] = c;
			if (c == 'R') b[i][k] = 'G';
			else b[i][k] = c;
		}
		scanf("%1c", &c);
	}
}

void dfs(int y, int x, int cnt, char a[100][100], int check[100][100]) {
	queue<pair<int, int>> q;
	char target = a[y][x];
	check[y][x] = cnt;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 > nx || nx >= n || 0 > ny || ny >= n) continue;

			if (check[ny][nx] == 0 && a[ny][nx] == target) {
				check[ny][nx] = cnt;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	char a[100][100]{};
	char b[100][100]{};
	insertData(a, b);
	int checka[100][100]{};
	int checkb[100][100]{};

	int cnta = 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (checka[i][k] == 0) {
				dfs(i, k, cnta, a, checka);
				cnta += 1;
			}
		}
	}
	int cntb = 1;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (checkb[i][k] == 0) {
				dfs(i, k, cntb, b, checkb);
				cntb += 1;
			}
		}
	}
	printf("%d %d", cnta - 1, cntb - 1);
}