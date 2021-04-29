#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<int> a[], int start, int visit[]) {
	if (visit[start]) {
		//방문한 경우 빠져나옴
		return;
	}
	visit[start] = true;

	for (int i = 0; i < a[start].size(); i++) {
		//인접노드 방문
		int x = a[start][i];
		dfs(a, x, visit);
	}
}


int checkVisit(int visit[], int N) {
	for (int i = 1; i < N + 1; i++) {
		if (visit[i] == 0) return i;
	}
	return -1;
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	vector<int>* a = new vector<int>[N + 1];
	int* visit = new int[N + 1]();

	int x, y;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i < N + 1; i++) {
		sort(a[i].begin(), a[i].end());
	}

	int s, count = 1;
	dfs(a, 1, visit);

	while (1) {
		s = checkVisit(visit, N);
		if (s == -1) {
			printf("%d", count);
			break;
		}
		count++;
		dfs(a, s, visit);
	}
}