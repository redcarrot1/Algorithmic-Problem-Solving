#include <iostream>
using namespace std;

int main() {
	int n, m, k, total, team=0;
	scanf("%d %d %d", &n, &m, &k);

	if (n / 2 > m) {
		team = m;
		total = n+m - 3*team;
	}
	else if (n / 2 <= m) {
		team = n/2;
		total = n + m - 3 * team;
	}
	//printf("���� ����: %d, ���� �ο�: %d\n", team, total);

	while(1){
		if (total >= k) break;
		total += 3;
		team--;
	}
	printf("%d", team);
}