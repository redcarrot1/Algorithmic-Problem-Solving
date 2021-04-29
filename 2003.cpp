#include <iostream>
#include <vector>	
using namespace std;

int main() {
	int num, n, reach, count=0;
	int arr[10000] = { 0, };
	scanf("%d %d", &num, &reach);
	for (int i = 0; i < num; i++) {
		scanf("%d", &n);
		arr[i] = n;
	}

	int l=0, h=0;
	int sum = 0;

	while (1) {
		if (sum >= reach) sum -= arr[l++];
		else if (h == num) break;
		else sum += arr[h++];

		if (sum == reach) count++;
	}
	printf("%d", count);
}