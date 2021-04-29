#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// �θ� ��带 ������
int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}
// �θ� ��带 ����
void unionParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	// �� ���ڰ� ���� �θ�� ����
	if (a < b) set[b] = a;
	else set[a] = b;
}
// ���� �θ� �������� Ȯ��
int find(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main(void) {
	int n = 7;
	int m = 11;
	cin >> n >> m;
	vector<Edge> v;
	
	for (int i = 0; i < m; i++) {
		int x, y, g;
		cin >> x >> y >> g;
		v.push_back(Edge(x, y, g));
	}


	// ������ ������� �������� ����
	sort(v.begin(), v.end());
	// �� ������ ���Ե� �׷����� ������� ����
	int set[10001];
	for (int i = 0; i < n; i++) {
		set[i] = i;
	}
	// �Ÿ��� ���� 0���� �ʱ�ȭ
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// ������ �θ� ����Ű�� �ʴ� ���, �� ����Ŭ
		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
}