#include<stdio.h>
#include <math.h>
using namespace std;

int end;
int a[10000001];

void primeNumberSieve() {

    // 1. 배열을 생성하여 초기화한다.
    for (int i = 2; i <= end; i++) {
        a[i] = i;
    }

    // 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
    // (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
   // int tmp = (int)sqrt(end);
    for (int i = 2; i*i <= end; ++i) {
        if (a[i] == 0) continue; // 이미 지워진 수라면 건너뛰기

        // 이미 지워진 숫자가 아니라면, 그 배수부터 출발하여, 가능한 모든 숫자 지우기
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