#include <stdio.h>

int main() {
	long long n, m;
	int two = 0, five = 0;
	int two2 = 0, five2 = 0;
	int two3 = 0, five3 = 0;

	scanf("%lld %lld", &n, &m);
	
	for (long long i = 5; i <= n; i *= 5) five += n / i;
	for (long long i = 2; i <= n; i *= 2) two += n / i;

	for (long long i = 5; i <= m; i *= 5) five2 += m / i;
	for (long long i = 2; i <= m; i *= 2) two2 += m / i;

	for (long long i = 5; i <= (n-m); i *= 5) five3 += (n - m) / i;
	for (long long i = 2; i <= (n-m); i *= 2) two3 += (n - m) / i;

	five =five-five2-five3;
	two =two-two2-two3;
	

	if (two > five)printf("%d", five);
	else printf("%d", two);

}