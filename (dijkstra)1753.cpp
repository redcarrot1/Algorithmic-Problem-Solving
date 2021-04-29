#include <iostream>
#include <vector>
#include <queue>
#define int_max 2147483647
//�켱���� ť�� �̿��� ���ͽ�Ʈ�� ����
//grape[u] <v, w> u���� v�� ���� ����ġ w

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
	// V��ŭ �迭�� INT_MAX�� �ʱ�ȭ
	vector<int> dist(num+1, int_max);
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
	vector<int> ans=dijkstra(start);
	for (int i = 1; i <= num; i++) {
		if (ans[i] == int_max) cout << "INF\n";
		else cout << ans[i] << '\n';
	}
}


/*
�켱����ť�� ������� �ʴ� ���ͽ�Ʈ��
�� �۵��ϴ����� �𸣰ڴ�.
������ ������� �� ȿ�����̴�.

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
	//�ʱ�ȭ. �Ÿ����� d[i]=2147483647
	//�湮������ s[i]=-1
	for (int i = 1; i <= num; i++) {
		d[i] = 2147483647;
		s[i] = -1;
	}
}

int findMin() {
	//s�� ����x && d[]���� �ּ�
	int minIndex = 1;
	int flag = 0;

	for (int i = 1; i <= num; i++) {
		if (s[i] != -1) continue;
		if (d[i] < d[minIndex]) minIndex = i;
	}

	return minIndex;
}

void relax(int index) {
	//d[v]������Ʈ

	for (int i = 0; i < grape[index].size(); i++) {
		int k = grape[index][i].first;	//K�� ������� �ε���
		int kdist = grape[index][i].second; //k�� index�� ����ġ

		if (s[k] == -1) {//������� && s�� ����x
			//�Ÿ� D ������Ʈ
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

	//���۳�忡 ���ؼ� �Ÿ�0, �׸��� S�� ����
	d[start] = 0;
	s[start] = 1;
	counts++;
	//������Ʈ
	relax(start);

	while (counts < num) {
		index = findMin(); //index= s�� ����x && d�߿� �ּ�
		s[index] = 1; //�� �ε����� ���� ����
		relax(index); //������Ʈ
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