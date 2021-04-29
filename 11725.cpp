#include <iostream>

using namespace std;

typedef struct link{
	int data;
	link* next=NULL;
}link;

void insertNode(int x, int y, link arr[]) {
	link* xlink = &arr[x];
	while (1) {
		if (xlink->next == NULL) {
			link* node = new link;
			node->data = y;
			xlink->next = node;
			break;
		}
		xlink = xlink->next;
	}
}

void makeParent(int parent[], int x, link arr[]) {
	//parent[x의 자식들] = x

	link* next = arr[x].next;
	while (1) {
		if (parent[next->data] == 0) { //아직 방문 안한 노드면
			parent[next->data] = x;
			makeParent(parent, next->data, arr);
		}
		if (next->next == NULL) break;
		next = next->next;
	}
}

void insertData(link arr[], int nodenum) {
	int x, y;
	for (int i = 0; i < nodenum - 1; i++) {

		scanf("%d", &x);
		scanf("%d", &y);
		insertNode(x, y, arr);
		insertNode(y, x, arr);
	}
}

int main() {
	int nodenum;
	scanf("%d", &nodenum);
	link* arr = new link[nodenum + 1];

	insertData(arr, nodenum);


	int* parent = new int[nodenum + 1]();
	parent[1] = 1;
	makeParent(parent, 1, arr);

	for (int i = 2; i < nodenum + 1; i++) {
		printf("%d\n", parent[i]);
	}
}