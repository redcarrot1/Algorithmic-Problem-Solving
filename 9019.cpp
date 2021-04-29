#include <iostream>
#include <string>
#include <queue>
using namespace std;

int a, b;

int D(int num) {
	return (2 * num) % 10000;
}

int S(int num) {
	return (num + 9999) % 10000;
}

int L(int num) {
	return  (num * 10) % 10000 + (num / 1000);
}

int R(int num) {
	return num / 10 + (num % 10) * 1000;
}

void bfs(string visit[]) {
	queue<int> q;
	q.push(D(a));
	visit[D(a)].append("D");
	
	if (visit[S(a)].empty()) {
		visit[S(a)].append("S");
		q.push(S(a));
	}
	if (visit[L(a)].empty()) {
		visit[L(a)].append("L");
		q.push(L(a));
	}
	if (visit[R(a)].empty()) {
		visit[R(a)].append("R");
		q.push(R(a));
	}
	

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		if (current == b) {
			cout << visit[current] << "\n";
			break;
		}

		int next;
		string s;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				next = D(current);
				s = "D";
			}
			else if (i == 1) {
				next = S(current);
				s = "S";
			}
			else if (i == 2) {
				next = L(current);
				s = "L";
			}
			else if (i == 3) {
				next = R(current);
				s = "R";
			}

			if (visit[next].empty()) {
				visit[next] = visit[current] + s;
				//visit[next].append(s);
				q.push(next);
			}
		}
	}
}

int main() {
	int testCase;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++) {
		string visit[10000];
		scanf("%d %d", &a, &b);
		bfs(visit);
	}


	//int a = 1234;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));

	//a = 123;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));
	//a = 1240;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));
	//a = 1023;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));
	//a = 12;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));
	//a = 9000;
	//printf("%d ->  L: %d, R: %d\n", a, L(a), R(a));

	//a = 9999;
	//printf("%d ->  D: %d, S: %d\n", a, D(a), S(a));

	//a = 0;
	//printf("%d ->  D: %d, S: %d\n", a, D(a), S(a));

	//a = 1;
	//printf("%d ->  D: %d, S: %d\n", a, D(a), S(a));

	//a = 1234;
	//printf("%d ->  D: %d, S: %d\n", a, D(a), S(a));
}