#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[1000] = { 0, };
	int n, sum=0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		sum += arr[i] * (n - i);
	}
	printf("%d", sum);

}