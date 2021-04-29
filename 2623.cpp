#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//a[x] : x이후 이루어져야 하는 task
vector<int> a[1001];

//inDegree[i]: i번 노드를 수행하기 전에 수행되어야할 task의 개수
int inDegree[1001];
int n, m;

void topologySort() {
	int result[1001];
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입합니다.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	// 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문
	for (int i = 1; i <= n; i++) {
		// n개를 방문하기 전에 큐가 비어버리면 사이클이 발생
		if (q.empty()) {
			printf("0");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// 새롭게 진입차수가 0이 된 정점을 큐에 삽입
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", result[i]);
	}
}

int main() {
	cin >> n >> m;
	int k;
	for (int i = 0; i < m; i++) {
		cin >> k;
		if (k <= 1) continue;
		queue<int> temp;
		int t;
		for (int q = 0; q < k; q++) {
			cin >> t;
			if (temp.empty()) inDegree[t] -= 1;
			temp.push(t);

		}

		int top = temp.front();
		inDegree[top] += 1;
		temp.pop();
		while (!temp.empty()) {
			a[top].push_back(temp.front());
			top = temp.front();
			inDegree[top] += 1;
			temp.pop();
		}
	}
	topologySort();
}