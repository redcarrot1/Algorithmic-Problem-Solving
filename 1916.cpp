#include <iostream>
#include <vector>
#include <queue>
#define int_max 2147483647
//�켱���� ť�� �̿��� ���ͽ�Ʈ�� ����
//grape[u] <v, w> u���� v�� ���� ����ġ w

using namespace std;
int num;
int start, goal;
vector<pair<int, int>> grape[1001];

void makeGrape() {
	int e;
	cin >> num >> e;

	int x, y, w;
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> w;
		grape[x].push_back(make_pair(y, w));
	}
	cin >> start >>goal;
}

vector<int> dijkstra(int src) {
	// V��ŭ �迭�� INT_MAX�� �ʱ�ȭ
	vector<int> dist(num + 1, int_max);
	dist[src] = 0; // �������� 0���� �ʱ�ȭ �Ѵ�. 

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, src)); // �������� ó������ �켱���� ť�� ����

	while (!pq.empty()) {
		// �켱���� ť�� ���� ����ġ�� �� ������ ������ �ٲپ��ش�.
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		// ���� ���� ���� �ͺ��� �� ª�� ��θ� �˰� �ִٸ� ���� �������� �����Ѵ�.
		if (dist[here] < cost)
			continue;

		// ������ �������� ��� �˻�.
		for (int i = 0; i < grape[here].size(); i++) {
			int there = grape[here][i].first;
			int nextDist = cost + grape[here][i].second;

			// �� ª�� ��θ� �߰��ϸ�, dist[]�� �����ϰ� �켱���� ť�� �ִ´�.
			// dist ���Ϳ��� ������ -> there ��ġ������ �ִ� �Ÿ��� ����ִ�.
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				/*
				���⼭ -�� �ִ� ����?
				priority_queue STL�� �⺻������ ���� ū ���Ұ� ���� ������ ť�� ����
				���� �Ÿ��� ��ȣ�� �ٲ㼭 �Ÿ��� ���� �������� ���������� �ϱ� ����
				*/
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	makeGrape();
	vector<int> ans = dijkstra(start);
	cout << ans[goal];
	/*for (int i = 1; i <= num; i++) {
		if (ans[i] == int_max) cout << "INF\n";
		else cout << ans[i] << '\n';
	}*/
}