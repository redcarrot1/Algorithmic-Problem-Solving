#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
	int testCase, N;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		int count = 0;
		scanf("%d", &N);
		vector<int>* a = new vector<int>[N + 1];
		int* visit = new int[N + 1]();

		int x;
		for (int i = 0; i < N; i++) {
			scanf("%d", &x);
			a[i + 1].push_back(x);
		}

		while (1) {
			int s = checkVisit(visit, N);
			if (s == -1) {
				printf("%d\n", count);
				delete[] visit;
				delete[] a;
				break;
			}
			count++;
			dfs(a, s, visit);
		}
	}
}