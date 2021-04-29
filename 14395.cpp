#include <iostream>
#include <set>
#include <string>
#include <queue>
const long long lim=1000000000LL;
using namespace std;

long long s, goal;

int main() {
	cin >> s >> goal;

	if (s == goal) {
		cout << "0";
		return 0;
	}

	queue < pair<long long, string>> q;
	set<long long> check;
	
	q.push(make_pair(s, ""));
	check.insert(s);
	
	while (!q.empty()) {
		long long x = q.front().first;
		string str = q.front().second;
		q.pop();

		if (x == goal) {
			cout << str;
			return 0;
		}

		if (0 <= x*x && x * x <= lim && check.count(x * x) == 0) {
			q.push(make_pair(x * x, str + "*"));
			check.insert(x * x);
		}

		if (0 <= x+x &&x + x <= lim && check.count(x + x) == 0) {
			q.push(make_pair(x + x, str + "+"));
			check.insert(x + x);
		}

		if (check.count(0) == 0) {
			q.push(make_pair(0, str + "-"));
			check.insert(0);
		}

		if (check.count(1) == 0) {
			q.push(make_pair(1, str + "/"));
			check.insert(1);
		}
	}

	cout << "-1";
}