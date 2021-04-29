#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
/*
step 1) 트리에서 임의의 정점 v1 에서 가장 먼 정점 v2를 찾는다.
step 2) v2와 v2 에서 가장 먼 정점 v3 사이의 거리를 찾는다.
step 3) 이 v2 와 v3 사이의 거리를 구하면 그게 트리의 지름이 된다.
*/

int n;
int dist[100001];
int check[100001] = { 0, };
int chk_n = 1;
vector<pair<int, int>> ad[100001];

int dist_dfs(int now) {
	check[now] = chk_n; //now노드는 check했음
	int ret = now;
	dist[now] = 0; //dist[now] : now노드와 가장 멀리 떨어지 노드의 거리
	for (int i = 0; i < ad[now].size(); i++) { //나와 연결된 노드 방문
		int next = ad[now][i].first; //next: 나와 연결된 노드번호
		if (check[next] != chk_n) { //아직 그 노드를 방문하지 않았다면
			int ret_next = dist_dfs(next); //ret_next: next와 가장 거리가 먼 노드(목적지 노드)
			if (dist[next] + ad[now][i].second > dist[now]) {//나와 연결된 노드의 dist+1이 현재 dist[now]보다 크다면
				dist[now] = dist[next] + ad[now][i].second; //서로 바꾸기
				ret = ret_next; //목적지 노드 새로고침
			}
		}
	}
	return ret; //목적지 노드 리턴
}

int main() {
	int node, distance, Node, k;

	/* 간선 입력 */

	scanf("%d", &Node);
	for (int j = 1; j <= Node; j++) {
		scanf("%d", &k);
		while (1) {
			scanf("%d", &node);
			if (node == -1) break;
			scanf("%d", &distance);
			ad[k].push_back(make_pair(node, distance));
			//printf("ad[%d]에 (%d, %d)를 추가합니다\n", k, node, distance);
		}
	}
	//printf("입력 끝\n");

	int v2 = dist_dfs(1);
	//printf("1과 가장 거리가 먼 [%d]노드의 거리: %d\n", v2, dist[1]);
	chk_n++;
	int v3 = dist_dfs(v2);
	//printf("%d과 가장 거리가 먼 [%d]노드의 거리: %d\n", v2, v3, dist[v2]);

	printf("%d", dist[v2]); // 지름
}