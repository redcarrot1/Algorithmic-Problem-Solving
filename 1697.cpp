#include <iostream>
#include <queue>
using namespace std;

int cb;
int visit[100001] = { 0, };

int insertData() {
	int cs;
	scanf("%d %d", &cs, &cb);
	return cs;
}


void bfs(int cs){
	queue<pair<int, int>> q;
	q.push(make_pair(cs, 0));
	visit[cs]++;

	while (!q.empty()) {
		int current = q.front().first;
		int cc = q.front().second;
		if (current == cb) {
			printf("%d", cc);
			break;
		}

		q.pop();

		int next;
		for (int i = 0; i < 3; i++) {
			if (i == 0 && current > 0) next = current - 1;
			else if (i == 1 && current <= 100000) next = current + 1;
			else if (i == 2 &&current<=50000) next = current * 2;
			else next = current;

			if (visit[next] == 0) {
				visit[next] = cc + 1;
				q.push(make_pair(next, cc + 1));
			}
		}
	}
}


int main() {
	int cs=insertData();
	bfs(cs);
}