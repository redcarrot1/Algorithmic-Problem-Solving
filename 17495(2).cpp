#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans = 2147483647;
int sheet[1001];
int d[121][121][121]{}; //l위치, r위치, 목표위치

/*
- Top-down
1. 문제의 최소문제 정의 (ex if(n==1) return 0;)
2. 메모가 되있다면 그거 사용 (ex if (memo[n] > 0) return memo[n];)
3. 아니라면 문제 풀어서 그 값 리턴.
*/

int go_(int i, int a, int b) {
	if (i == n + 1) {
		d[i][a][b] = 0;
		return  0;
	}
	if (d[i][a][b] != -1) return d[i][a][b];
	d[i][a][b] = 2147483647;
	d[i][a][b] = min(d[i][a][b], go_(i + 1, sheet[i], b) + abs(sheet[i] - a));
	d[i][a][b] = min(d[i][a][b], go_(i + 1, a, sheet[i]) + abs(sheet[i] - b));
	return d[i][a][b];
}

int sttonum(string temp) {
	if (temp[0] == 'C') return 1 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'D') return  3 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'E')  return 5 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'F') return 6 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'G') return 8 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'A') return 10 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else if (temp[0] == 'B') return 12 + 12 * (temp[1] - '0') + (temp.size() == 3);
	else return -1;
}

queue<int>q;
void bfs_(int i, int a, int b) {
	if (i == n + 1) return;
	if (d[i][a][b] == (d[i + 1][sheet[i]][b] + abs(sheet[i] - a))) {
		q.push(1);
		bfs_(i + 1, sheet[i], b);
	}
	else {
		q.push(2);
		bfs_(i + 1, a, sheet[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	memset(d, -1, sizeof(d));

	string rx, lx; //현재 위치

	cin >> lx >> rx >> n;

	string temp;
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		sheet[i] = sttonum(temp);
	}

	cout << go_(1, sttonum(lx), sttonum(rx)) << "\n";
	bfs_(1, sttonum(lx), sttonum(rx));
	while (!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
}