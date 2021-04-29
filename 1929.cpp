#include <stdio.h>
#include <math.h>
int number = 100000;
int a[1000001];

int start, end;
void primeNumberSieve() {

    // 1. �迭�� �����Ͽ� �ʱ�ȭ�Ѵ�.
    for (int i = 2; i <= end; i++) {
        a[i] = i;
    }

    // 2. 2���� �����ؼ� Ư�� ���� ����� �ش��ϴ� ���� ��� �����.
    // (���� �� �ڱ��ڽ��� ������ �ʰ�, �̹� ������ ���� �ǳʶڴ�.)
    int tmp = (int)sqrt(end);
    for (int i = 2; i <= tmp; i++) {
        if (a[i] == 0) continue; // �̹� ������ ����� �ǳʶٱ�

        // �̹� ������ ���ڰ� �ƴ϶��, �� ������� ����Ͽ�, ������ ��� ���� �����
        for (int j = 1+ i; j <= end; j++) {
            if (a[j] == 0) continue;
            if (a[j] % i == 0) a[j] = 0;
        }
    }

    // 3. 2���� �����Ͽ� �����ִ� ���� ��� ����Ѵ�.
    for (int i = start; i <= end; i++) {
        if (i == 1) continue;
        if (a[i] != 0) {
            printf("%d\n", a[i]);
        }
        
    }
}

int main() {
	scanf("%d", &start);
	scanf("%d", &end);
	
    primeNumberSieve();

}