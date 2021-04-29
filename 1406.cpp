#include <iostream>
#include <string>
using namespace std;

typedef struct dulist {
	char data;
	dulist* left=NULL;
	dulist* right=NULL;
}dulist;

int main() {
	char c;
	int count = 0;
	dulist* ago = NULL;

	dulist* start = new dulist;
	start->data = NULL;
	while (1) {
		scanf("%c", &c);
		if (int(c) == 10) break;

		dulist* d= new dulist;
		if (count == 0) {
			d->left = start;
			start->right = d;
		}
		else {
			ago->right = d;
			d->left = ago;
		}
		count = 1;
		d->data = c;
		ago = d;
	}
	
	dulist* pos = ago;
	int n;
	char order;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%c", &c);//엔터먹는용
		scanf("%c", &order);

		if (order == 'L') {
			if (pos->left== NULL) continue;
			pos = pos->left;
		}
		else if (order == 'D') {
			if (pos->right == NULL) continue;
			pos = pos->right;
		}
		else if (order == 'B') {
			if (pos->left == NULL) continue;
			if(pos->right !=NULL) pos->right->left = pos->left;
			pos->left->right = pos->right;
			pos = pos->left;
		}
		else if (order == 'P') {
			scanf("%c", &order);//스페이스먹는용
			scanf("%c", &order);
			dulist* d = new dulist;
			d->data = order;

			if (pos->right == NULL) {
				pos->right = d;
				d->left = pos;
				pos = d;
				continue;
			}
			pos->right->left = d;
			d->right = pos->right;
			pos->right = d;
			d->left = pos;
			pos = d;

		}
	}

	pos = start->right;
	while (1) {
		printf("%c", pos->data);
		if (pos->right == NULL) break;
		pos = pos->right;
	}


}