#include <iostream>
#include <vector>
#include <queue>
#define int_max 2147483647
//우선순위 큐를 이용한 다익스트라 구현
//grape[u] <v, w> u에서 v로 가는 가중치 w

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
	// V만큼 배열을 INT_MAX로 초기화
	vector<int> dist(num + 1, int_max);
	dist[src] = 0; // 시작점은 0으로 초기화 한다. 

	priority_queue<pair<int, int> > pq;

	pq.push(make_pair(0, src)); // 시작점을 처음으로 우선순위 큐에 삽입

	while (!pq.empty()) {
		// 우선순위 큐에 음의 가중치로 들어가 있으니 양으로 바꾸어준다.
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		// 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있다면 지금 꺼낸것을 무시한다.
		if (dist[here] < cost)
			continue;

		// 인접한 정점들을 모두 검사.
		for (int i = 0; i < grape[here].size(); i++) {
			int there = grape[here][i].first;
			int nextDist = cost + grape[here][i].second;

			// 더 짧은 경로를 발견하면, dist[]를 갱신하고 우선순위 큐에 넣는다.
			// dist 벡터에는 시작점 -> there 위치까지의 최단 거리가 담겨있다.
			if (dist[there] > nextDist)
			{
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
				/*
				여기서 -로 넣는 이유?
				priority_queue STL은 기본적으로 가장 큰 원소가 위로 가도록 큐를 구성
				따라서 거리의 부호를 바꿔서 거리가 작은 정점부터 꺼내지도록 하기 위함
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