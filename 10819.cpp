#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[8] = { 0, };
	int sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int max_sum = 0;

	do {
		sum = 0;
		for (int i = 0; i < n - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		if (max_sum < sum) max_sum = sum;
	}while (next_permutation(arr, arr + n));

	printf("%d", max_sum);
}