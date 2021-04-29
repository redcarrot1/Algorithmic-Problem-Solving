#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/

int main() {
	queue<int> q;
	int n;
	cin >> n;

	string str;
	while (n--) {
		cin >> str;

		if (str == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else if (str == "front") {
			if (q.empty()) { cout << "-1\n"; continue; }
			cout << q.front()<<'\n';
		}
		else if (str == "back") {
			if (q.empty()) { cout << "-1\n"; continue; }
			cout << q.back() << '\n';
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "empty") {
			if (q.empty()) { cout << "1\n"; continue; }
			cout << "0\n";
		}
		else if (str == "pop") {
			if (q.empty()) { cout << "-1\n"; continue; }
			cout << q.front() << "\n";
			q.pop();
		}
	}
}

/*15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
*/