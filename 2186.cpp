#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

/*
1. 문자열 0 검사-> 발견하면 1이라 쓰기
2. 발견한 문자열을 기준으로 k칸 까지 검사 -> 발견시 +=자신의 숫자
*/

char a[101][101];
string str;
int check[101][101][81]{}; //y, x, 찾는 문자열 i번째에서 쓰임
int n, m, k, num[81]{};

void insertData() {
	scanf("%d %d %d", &n, &m, &k);
	char enter;
	scanf("%c", &enter);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1c", &a[i][j]);
		}
		scanf("%c", &enter);
	}
	cin >> str;
}

void firstcheck(queue<pair<int, int>>& q) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == str[0]) {
				q.push(make_pair(i, j));
				check[i][j][0] = 1;
				num[0] += 1;
			}
		}
	}
}

int main() {
	insertData();
	queue<pair<int, int>>q;
	firstcheck(q);

	int cnt = 1;

	while (1) {
		if (cnt == str.size()) break;

		for (int z = 0; z < num[cnt - 1]; z++) {
			int y = q.front().first;
			int x = q.front().second;

			q.pop();
			int ny, nx;
			for (int i = -k; i <= k; i++) {
				if (i == 0) continue;
				for (int k = 0; k < 2; k++) {
					if (k == 0) {
						ny = y + i;
						nx = x;
					}
					else {
						ny = y;
						nx = x + i;
					}

					if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;

					if (a[ny][nx] == str[cnt]) {
						if (check[ny][nx][cnt] == 0) {
							q.push(make_pair(ny, nx));
							num[cnt] += 1;
						}
						check[ny][nx][cnt] += check[y][x][cnt - 1];
					}
				}
			}
		}
		cnt += 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == str[str.size() - 1]) {
				ans += check[i][j][cnt - 1];
			}
		}
	}
	cout << ans;
}