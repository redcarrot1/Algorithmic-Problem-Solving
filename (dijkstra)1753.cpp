#include <iostream>
#include <vector>
#include <queue>
#define int_max 2147483647
//우선순위 큐를 이용한 다익스트라 구현
//grape[u] <v, w> u에서 v로 가는 가중치 w

using namespace std;
int num;
int start;
vector<pair<int, int>> grape[20001];

void makeGrape() {
	int e;
	cin >> num >> e >> start;

	int x, y, w;
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> w;
		grape[x].push_back(make_pair(y, w));
	}
}

vector<int> dijkstra(int src) {
	// V만큼 배열을 INT_MAX로 초기화
	vector<int> dist(num+1, int_max);
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
	vector<int> ans=dijkstra(start);
	for (int i = 1; i <= num; i++) {
		if (ans[i] == int_max) cout << "INF\n";
		else cout << ans[i] << '\n';
	}
}


/*
우선순위큐를 사용하지 않는 다익스트라
잘 작동하는지는 모르겠다.
간선이 적은경우 더 효율적이다.

#include <iostream>
#include <vector>
using namespace std;
int num;
int start;
int d[20001];
int s[20001];
vector<pair<int, int>> grape[20001];

void makeGrape() {
	int e;
	cin >> num >> e >> start;

	int x, y, w;
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> w;
		grape[x].push_back(make_pair(y, w));
	}
}

void setinit() {
	//초기화. 거리무한 d[i]=2147483647
	//방문안했음 s[i]=-1
	for (int i = 1; i <= num; i++) {
		d[i] = 2147483647;
		s[i] = -1;
	}
}

int findMin() {
	//s에 포함x && d[]에서 최소
	int minIndex = 1;
	int flag = 0;

	for (int i = 1; i <= num; i++) {
		if (s[i] != -1) continue;
		if (d[i] < d[minIndex]) minIndex = i;
	}

	return minIndex;
}

void relax(int index) {
	//d[v]업데이트

	for (int i = 0; i < grape[index].size(); i++) {
		int k = grape[index][i].first;	//K는 인접노드 인덱스
		int kdist = grape[index][i].second; //k랑 index의 가중치

		if (s[k] == -1) {//인접노드 && s에 포함x
			//거리 D 업데이트
			if (d[k] > d[index] + kdist) {
				d[k] = d[index] + kdist;
			}
		}
	}
}

void printD() {
	for (int i = 1; i <= num; i++) {
		if (d[i] == 2147483647) { cout << "INF\n"; }
		else cout << d[i] << '\n';
	}
}

void dijkstra(int start) {
	int counts = 0, index;
	setinit();

	//시작노드에 대해선 거리0, 그리고 S에 포함
	d[start] = 0;
	s[start] = 1;
	counts++;
	//업데이트
	relax(start);

	while (counts < num) {
		index = findMin(); //index= s에 포함x && d중에 최소
		s[index] = 1; //그 인덱스는 지금 포함
		relax(index); //업데이트
		counts++;
	}

	printD();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	makeGrape();
	//printGrape(grape);
	//cout << "\n======================\n";
	dijkstra(start);
}*/