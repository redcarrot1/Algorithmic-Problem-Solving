#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = { 0, };
int n, k;

bool compare(int a, int b) {
	return a > b;
}

int main() {
	int count = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n, compare);

	for (int i = 0; i < n-1; i++) {
		while (k / arr[i]) {
			k = k - arr[i];
			count++;
		}
	}
	count = count + k;
	printf("%d", count);
}