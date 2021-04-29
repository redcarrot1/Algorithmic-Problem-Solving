#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<int> a[], int start, int visit[], int i, int k) {
	if (visit[start]) {
		if (i == start) return 0;
		return 1;
	}
	visit[start] = true;
	
	int x = a[start][k];
	return dfs(a, x, visit, i, k);
}


void setVisit(int visit[], int N) {
	for (int i = 0; i < N + 1; i++) {
		visit[i] = 0;
	}
}


int main() {
	int testCase, num, count, x;
	scanf("%d", &testCase);
	
	vector<int> a[100001];
	int visit[100001] = { 0, };
	for (int k = 0; k < testCase; k++) {
		scanf("%d", &num);
		count = 0;

		for (int i = 1; i <= num; i++) {
			scanf("%d", &x);
			a[i].push_back(x);
		}


		for (int i = 1; i <= num; i++) {
			setVisit(visit, num);
			count+=dfs(a, i,visit, i, k);
		}
		printf("%d\n", count);

	}
}