#include <stdio.h>

typedef struct p {
	int n;
	p* right=NULL;
}p;

int main() {
	int k, N;
	scanf("%d %d", &N, &k);
	p* first = new p;
	first->n = 1;
	p* ago = first;

	for (int i = 2; i <= N; i++) {
		p* person = new p;
		person->n = i;
		ago->right = person;
		ago = person;
	}
	ago->right = first;

	printf("<");
	
	for (int i = 0; i < N; i++) {
		for (int i = 0; i < k-1; i++) {
			ago = ago->right;
		}
		if (i != N - 1) printf("%d, ", ago->right->n);
		else printf("%d>", ago->right->n);
		ago->right = ago->right->right;
	}
	
}