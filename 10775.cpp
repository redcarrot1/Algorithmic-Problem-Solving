#include <stdio.h>
using namespace std;
/*
1. ������ �������� �ڽ��� ��ŷ�� �� �ִ� ����Ʈ �� ���� �ָ� ��ŷ�ؾ��Ѵ�.
2. ��, best�� a. ���� �ȵȴٸ� a-1, �װ͵� �ȵȴٸ� a-2, ... 0���� ���ٸ� �̹� �����Ŵ�.
3. gate�̿� ����/�Ұ����� �Ǻ��ϱ� ���� �迭�� ����Ѵٸ� n^2�� �����Ƿ� �ð� �ʰ�
4. �и� ������ ����Ͽ� k�� gate�� ��ŷ���ߴٸ� k-1�� gate�� unite����
5. �� ��, k�� k-1������ ����. ��, k�� �θ�� k-1�̴�.
6. ���� ����Ⱑ ���� k�� gate���� ��ŷ�� �����ϴٸ� parent[k]�� ��ŷ�ϸ� �ɰ��̴�.
7. parent[k]==0�̸� �� ������ ��ŷ�� ���� �����Ƿ�, ������� ���� ����� ���� ����ϸ� �ȴ�.
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