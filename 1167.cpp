#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
/*
step 1) Ʈ������ ������ ���� v1 ���� ���� �� ���� v2�� ã�´�.
step 2) v2�� v2 ���� ���� �� ���� v3 ������ �Ÿ��� ã�´�.
step 3) �� v2 �� v3 ������ �Ÿ��� ���ϸ� �װ� Ʈ���� ������ �ȴ�.
*/

int n;
int dist[100001];
int check[100001] = { 0, };
int chk_n = 1;
vector<pair<int, int>> ad[100001];

int dist_dfs(int now) {
	check[now] = chk_n; //now���� check����
	int ret = now;
	dist[now] = 0; //dist[now] : now���� ���� �ָ� ������ ����� �Ÿ�
	for (int i = 0; i < ad[now].size(); i++) { //���� ����� ��� �湮
		int next = ad[now][i].first; //next: ���� ����� ����ȣ
		if (check[next] != chk_n) { //���� �� ��带 �湮���� �ʾҴٸ�
			int ret_next = dist_dfs(next); //ret_next: next�� ���� �Ÿ��� �� ���(������ ���)
			if (dist[next] + ad[now][i].second > dist[now]) {//���� ����� ����� dist+1�� ���� dist[now]���� ũ�ٸ�
				dist[now] = dist[next] + ad[now][i].second; //���� �ٲٱ�
				ret = ret_next; //������ ��� ���ΰ�ħ
			}
		}
	}
	return ret; //������ ��� ����
}

int main() {
	int node, distance, Node, k;

	/* ���� �Է� */

	scanf("%d", &Node);
	for (int j = 1; j <= Node; j++) {
		scanf("%d", &k);
		while (1) {
			scanf("%d", &node);
			if (node == -1) break;
			scanf("%d", &distance);
			ad[k].push_back(make_pair(node, distance));
			//printf("ad[%d]�� (%d, %d)�� �߰��մϴ�\n", k, node, distance);
		}
	}
	//printf("�Է� ��\n");

	int v2 = dist_dfs(1);
	//printf("1�� ���� �Ÿ��� �� [%d]����� �Ÿ�: %d\n", v2, dist[1]);
	chk_n++;
	int v3 = dist_dfs(v2);
	//printf("%d�� ���� �Ÿ��� �� [%d]����� �Ÿ�: %d\n", v2, v3, dist[v2]);

	printf("%d", dist[v2]); // ����
}