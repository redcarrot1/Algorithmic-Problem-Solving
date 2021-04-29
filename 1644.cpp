#include <iostream>
#include <vector>
//21min
using namespace std;
vector<int> prime;
int number, ans = 0;
int start = 0, End = 0;
int sum = 0;

void primeNumberSieve() {
	scanf("%d", &number);

	// 1. �迭�� �����Ͽ� �ʱ�ȭ�Ѵ�.
	int* a = new int[number + 1];
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}

	// 2. 2���� �����ؼ� Ư�� ���� ����� �ش��ϴ� ���� ��� �����.
	// (���� �� �ڱ��ڽ��� ������ �ʰ�, �̹� ������ ���� �ǳʶڴ�.)
	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue; // �̹� ������ ����� �ǳʶٱ�

		// �̹� ������ ���ڰ� �ƴ϶��, �� ������� ����Ͽ�, ������ ��� ���� �����
		for (int j = 2 * i; j <= number; j += i) {
			a[j] = 0;
		}
	}

	// 3. 2���� �����Ͽ� �����ִ� ���� ��� ����Ѵ�.
	for (int i = 2; i <= number; i++) {
		if (a[i] != 0) {
			prime.push_back(a[i]);
		}
	}
}

int main() {
	primeNumberSieve();
	if (prime.size() == 0) {
		printf("0");
		return 0;
	}
	sum = prime[0];
	while(1) {
		if (start > End) break;

		if (sum > number) {
			sum -= prime[start];
			if (start == prime.size() - 1) break;
			start++;
		}
		else if (sum < number) {
			if (End == prime.size() - 1) break;
			End++;
			sum += prime[End];
		}
		else {
			ans++;
			if (End == prime.size() - 1) break;
			End++;
			sum += prime[End];
		}
	}
	printf("%d", ans);
}