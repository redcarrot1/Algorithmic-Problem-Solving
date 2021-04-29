#include <deque>
#include <string>
#include <iostream>
using namespace std;

int main() {
	deque<int> dq;
	int order, n;
	cin >> order;

	string str;
	for (int i = 0; i < order; i++) {
		cin >> str;
		if (str == "push_back") {
			cin >> n;
			dq.push_back(n);
		}

		else if (str == "push_front") {
			cin >> n;
			dq.push_front(n);
		}

		else if (str == "pop_front") {
			if (dq.size() == 0) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
			dq.pop_front();
		}

		else if (str == "pop_back") {
			if (dq.size() == 0) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
			dq.pop_back();
		}

		else if (str == "size") {
			cout << dq.size() << "\n";
		}

		else if (str == "empty") {
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}

		else if (str == "front") {
			if (dq.size() == 0) {
				cout << "-1\n";
				continue;
			}
			cout << dq.front() << "\n";
		}

		else if (str == "back") {
			if (dq.size() == 0) {
				cout << "-1\n";
				continue;
			}
			cout << dq.back() << "\n";
		}
	}
}