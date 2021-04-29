#include <iostream>
using namespace std;

int main() {
	long long num[10] = { 0, };
	long long remind[3] = { 0, };
	int n;
	char c;
	while (1) {
		scanf("%c", &c);
		n = c - '0';
		if (n < 0 ||n >9) break;
		num[n]++;

		if (n == 1 || n== 4 || n == 7) remind[1]++;
		else if (n == 2 || n== 5 || n == 8) remind[2]++;
	}

	if (num[0] == 0 || (2*remind[2] + remind[1]) %3 !=0) {
		printf("-1");
		return 0;
	}

	for (int i = 9; i >=0; i--) {
		for (long long k = 0; k < num[i]; k++) {
			printf("%d", i);
		}
	}
}