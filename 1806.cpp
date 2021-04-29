#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> arr;
int S;
int N;

void insertData() {
	scanf("%d %d", &N, &S);
	
	int n;
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		arr.push_back(n);
	}
}

int main() {
	insertData();
	int start = 0, end = 0;
	int min = N+1;

	int sum = arr[0];

	while (1) {
		if (end >= N) break;

		if (sum < S) {
			end++;
			if (end >= N) break;
			sum += arr[end];
		}
		else if (sum > S) {
			if (min > end - start + 1) min = end - start + 1;
			sum -= arr[start];
			start++;
		}
		else {
			if (min > end - start + 1) min = end - start + 1;
			end++;
			if (end >= N) break;
			sum += arr[end];
		}
	}
	if (min == N + 1) printf("0");
	else printf("%d", min);

}