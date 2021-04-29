#include<stdio.h>
#include <math.h>
using namespace std;

int end;
int a[10000001];

void primeNumberSieve() {

    // 1. �迭�� �����Ͽ� �ʱ�ȭ�Ѵ�.
    for (int i = 2; i <= end; i++) {
        a[i] = i;
    }

    // 2. 2���� �����ؼ� Ư�� ���� ����� �ش��ϴ� ���� ��� �����.
    // (���� �� �ڱ��ڽ��� ������ �ʰ�, �̹� ������ ���� �ǳʶڴ�.)
   // int tmp = (int)sqrt(end);
    for (int i = 2; i*i <= end; ++i) {
        if (a[i] == 0) continue; // �̹� ������ ����� �ǳʶٱ�

        // �̹� ������ ���ڰ� �ƴ϶��, �� ������� ����Ͽ�, ������ ��� ���� �����
        for (int j = 1 + i; j <= end; j++) {
            if (a[j] == 0) continue;
            if (a[j] % i == 0) a[j] = 0;
        }
    }
    
}

int main() {
    scanf("%d", &end);
    if (end == 1) return 0;
    //primeNumberSieve();

    int p = 2;
    while (1) {
        if (end == 1) break;
        if (end % p) p++;
        else {
            printf("%d\n", p);
            end = end / p;
        }
    }
}