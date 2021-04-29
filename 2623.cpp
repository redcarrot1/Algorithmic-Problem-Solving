#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//a[x] : x���� �̷������ �ϴ� task
vector<int> a[1001];

//inDegree[i]: i�� ��带 �����ϱ� ���� ����Ǿ���� task�� ����
int inDegree[1001];
int n, m;

void topologySort() {
	int result[1001];
	queue<int> q;

	// ���� ������ 0�� ��带 ť�� �����մϴ�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	// ������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮
	for (int i = 1; i <= n; i++) {
		// n���� �湮�ϱ� ���� ť�� �������� ����Ŭ�� �߻�
		if (q.empty()) {
			printf("0");
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// ���Ӱ� ���������� 0�� �� ������ ť�� ����
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