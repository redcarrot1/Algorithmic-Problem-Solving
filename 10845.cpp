#include <iostream>
#include <queue>
#include <string>
using namespace std;

/*
push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.*/

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