#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	long long a[1000000];
	int num;
	long long k;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%lld", &k);
		a[i] = k;
	}
	sort(a, a + num);

	long long maxnum = a[0]; //maxnum: 현재까지 개수가 가장 많은 숫자
	int count = 0, temp = 1; //count: maxnum의 개수, temp: 현재 세고있는 숫자의 개수
	for (int i = 0; i < num - 1; i++) {
		if (a[i] == a[i + 1]) {
			temp++;
			if (count < temp) {
				maxnum = a[i];
				count = temp;
			}
		}
		else temp = 1;
	}

	printf("%lld", maxnum);
}
