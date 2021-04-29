#include <iostream>
#include <queue>
using namespace std;

int goal;
int orign;
int prime[100000] = { 0, };

void insertData() {
	scanf("%d %d", &orign, &goal);
}

void primeNumberSieve() {
	for (int i = 2; i <= 10000; i++) {
		prime[i] = i;
	}

	// 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.
	// (지울 때 자기자신은 지우지 않고, 이미 지워진 수는 건너뛴다.)
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == 0) continue; // 이미 지워진 수라면 건너뛰기

		// 이미 지워진 숫자가 아니라면, 그	배수부터 출발하여, 가능한 모든 숫자 지우기
		for (int j = 2 * i; j <= 10000; j += i) {
			prime[j] = 0;
		}
	}
}

void bfs(int visit[100000]) {
	queue<int> q;

	q.push(orign);
	visit[orign]++;

	while (!q.empty()) {
		int current = q.front();
		q.pop();


		if (current == goal) {
			printf("%d\n", visit[current]-1);
			break;
		}

		int next;
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k <= 9; k++) {
				if (i == 0) next = (current / 10) * 10 + k;
				else if (i == 1) next = (current / 100) * 100 + 10 * k + current % 10;
				else if (i == 2) next = (current / 1000) * 1000 + 100 * k + current % 100;
				else if (i == 3 && k != 0) next = (current % 1000) + 1000 * k;
				else next = current;

				if (visit[next] == 0 && prime[next] != 0) {
					//printf("%d를 넣습니다(time: %d)\n", next, visit[current] + 1);
					visit[next] = visit[current] + 1;
					q.push(next);
				}
			}
		}
	}
}



int main() {
	int testCase;
	scanf("%d", &testCase);
	primeNumberSieve();

	for (int i = 0; i < testCase; i++) {

		int visit[100000] = { 0, };
		insertData();
		bfs(visit);
	}
}