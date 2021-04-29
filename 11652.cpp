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

	long long maxnum = a[0]; //maxnum: ������� ������ ���� ���� ����
	int count = 0, temp = 1; //count: maxnum�� ����, temp: ���� �����ִ� ������ ����
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
