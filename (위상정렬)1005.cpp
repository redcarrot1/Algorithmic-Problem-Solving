#include <iostream>
#include <queue>
using namespace std;

void topologySort(int n, int inDegree[], int result[], vector<int> a[]) {
	queue<int> q;
	// ���� ������ 0�� ��带 ť�� �����մϴ�.
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	// ������ ������ ����Ƿ��� ��Ȯ�� n���� ��带 �湮
	for (int i = 1; i <= n; i++) {
		// n���� �湮�ϱ� ���� ť�� �������� ����Ŭ��

		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			// ���Ӱ� ���������� 0�� �� ������ ť�� ��
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, goal;
		int a[1001]{};
		int inDegree[1001]{};
		int ans[1001]{};
		vector<int> v[1001];
		vector<int> parent[1001];

		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			ans[i] = a[i];
		}
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			parent[y].push_back(x);
			inDegree[y] += 1;
		}
		cin >> goal;

		int result[1001];
		topologySort(n, inDegree, result, v);

		ans[result[1]] = a[result[1]];

		for (int i = 2; i <= n; i++) {
			int next = result[i]; //next�� ���� ������ ans�� �и� �� �����������Ŵ�.

			for (int k = 0; k < parent[next].size(); k++) {
				if (ans[next] < ans[parent[next][k]] + a[next]) {
					ans[next] = ans[parent[next][k]] + a[next];
				}
			}
		}
		cout << ans[goal] << '\n';
	}
}