#include <iostream>
using namespace std;

int main() {
    int t, k;
    int d[41][2];
    d[0][0] = 1;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 1;
    for (int i = 2; i <= 40; i++) {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        printf("%d %d\n", d[k][0], d[k][1]);
    }
}