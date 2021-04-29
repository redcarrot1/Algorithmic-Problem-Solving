#include <stdio.h>

int two = 0, five = 0;

void fib(int n) {
	while (1) {
		if (n == 0) break;
		
		int temp = n;
		while (1) {
			if (temp % 2 == 0) {
				two++;
				temp = temp / 2;
			}
			else if (temp % 5 == 0) {
				five++;
				temp = temp / 5;
			}
			else break;
		}

		n--;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	
	fib(n);
	int count;

	if (two > five) count = five;
	else count = two;

	printf("%d", count);
}