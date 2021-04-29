#include <stdio.h>
using namespace std;
/*
1. 비행기는 가능한한 자신이 도킹할 수 있는 게이트 중 가장 멀리 도킹해야한다.
2. 즉, best는 a. 만약 안된다면 a-1, 그것도 안된다면 a-2, ... 0까지 간다면 이미 꽉찬거다.
3. gate이용 가능/불가능을 판별하기 위해 배열을 사용한다면 n^2이 나오므로 시간 초과
4. 분리 집합을 사용하여 k번 gate가 도킹당했다면 k-1번 gate과 unite하자
5. 이 때, k가 k-1밑으로 들어간다. 즉, k의 부모는 k-1이다.
6. 다음 비행기가 만약 k번 gate까지 도킹이 가능하다면 parent[k]에 도킹하면 될것이다.
7. parent[k]==0이면 이 비행기는 도킹할 곳이 없으므로, 현재까지 받은 비행기 수를 출력하면 된다.
*/
int g, p, a, i, cnt, empty_gate;
int parent[100001];

int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}

int main() {
    scanf("%d %d", &g, &p);
    for (i = 1; i <= g; ++i)
        parent[i] = i;

    for (i = 0; i < p; ++i) {
        scanf("%d", &a);
        empty_gate = find(a);
        if (empty_gate == 0)
            break;
        else {
            cnt++;
            unite(empty_gate, empty_gate - 1);
        }
    }
    printf("%d\n", cnt);
    return 0;
}