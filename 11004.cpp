#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n, k;

	scanf("%d %d", &n, &k);
	long long* N = new long long[n];

	for (long long i = 0; i < n; i++) {
		scanf("%lld", &N[i]);
	}
	sort(N, N + n);
	printf("%d", N[k - 1]);

	delete[]N;
}