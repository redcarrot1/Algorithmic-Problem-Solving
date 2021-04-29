#include <iostream>
using namespace std;

typedef struct node {
	char c = 'K';
	node* left = NULL;
	node* right = NULL;
}node;

node* search2(node* Node, char find)
{
	node* leftn;
	node* rightn;
	if (Node == NULL) return 0;
	// ���ϴ� Ű ���� �߰����� ���
	if (find == Node->c) return Node; // �ش� ����� �ּ� ��ȯ

	  // ã���� �ϴ� ������ ��ƮŰ���� �� ū ���
	else {
		leftn = search2(Node->left, find);
		rightn = search2(Node->right, find);
		if (leftn == 0) return rightn;
		else if (rightn == 0) return leftn;
	}
}

void preorder(node* Node) {
	if (Node != NULL) {
		cout << Node->c;
		preorder(Node->left);
		preorder(Node->right);
	}
}

void postorder(node* Node) {
	if (Node != NULL) {
		postorder(Node->left);
		postorder(Node->right);
		cout << Node->c;
	}
}

void inorder(node* Node) {
	if (Node != NULL) {
		inorder(Node->left);
		cout << Node->c;
		inorder(Node->right);
	}
}
int main() {
	int num;
	char n, l, r;
	scanf("%d", &num);
	scanf("%c", &n); //���͸Դ¿�
	scanf("%c %c %c", &n, &l, &r);

	node* start = new node;
	start->c = n;

	if (l != '.') {
		node* LNode = new node;
		start->left = LNode;
		LNode->c = l;
	}
	if (r != '.') {
		node* RNode = new node;
		start->right = RNode;
		RNode->c = r;
	}

	for (int i = 0; i < num - 1; i++) {
		scanf("%c", &n); //���͸Դ¿�
		scanf("%c %c %c", &n, &l, &r);

		node* Node = search2(start, n);

		if (l != '.') {
			node* LNode = new node;
			Node->left = LNode;
			LNode->c = l;
		}
		if (r != '.') {
			node* RNode = new node;
			Node->right = RNode;
			RNode->c = r;
		}
	}

	preorder(start);
	printf("\n");
	inorder(start);
	printf("\n");
	postorder(start);
}