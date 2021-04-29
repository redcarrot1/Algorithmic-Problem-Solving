#include <iostream>
#include <set>
#include <vector>
using namespace std;

int h, w, s;
char str[27];
char map[101][101];
pair<int, int> check[101][101];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

void insertData() {
	char c;
	cin >> h >> w >> s;
	scanf("%c", &c); //엔터먹는용;a
	for (int i = 0; i < s; i++) {
		scanf("%1c", &str[i]);
	}
	scanf("%c", &c); //엔터먹는용;

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			scanf("%1c", &map[i][k]);
		}
		scanf("%c", &c);
	}
}

void dfs(int y, int x, int cnt, int nowc) {
	//y,x까지 반복된 문자열 횟수=cnt, 문자열 s중 nowc번째 접근 중
	check[y][x] = make_pair(cnt, nowc);
	int nextc;

	if (nowc == s - 1) nextc = 0;
	else nextc = nowc + 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (0 > ny || ny >= h || 0 > nx || nx >= w) continue;

		if (map[ny][nx] == str[nextc]) {
			if (check[ny][nx].first != 0 || check[ny][nx].second != 0 || (ny == 0 && nx == 0)) {
				//cycle must not be included
				printf("-1");
				exit(0);
			}
			if (nowc == s - 1) dfs(ny, nx, cnt + 1, nextc);
			else dfs(ny, nx, cnt, nextc);
		}
	}
}

int main() {
	insertData();

	dfs(0, 0, 0, 0);

	//for (int i = 0; i < h; i++) {
	//	for (int k = 0; k < w; k++) {
	//		printf("(%d, %d) ", check[i][k].first, check[i][k].second);
	//	}
	//	printf("\n");
	//}

	int ansy=-1, ansx=-1, ans = -1;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if (check[i][k].second ==s-1 && check[i][k].first>ans) {
				ans = check[i][k].first;
				ansy = i;
				ansx = k;
				
			}
		}
	}
	if (ansx == -1) printf("-1");
	else printf("%d\n%d %d", ans+1, ansy+1, ansx+1);
}