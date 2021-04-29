#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> sub[1001]; //과목에 들어가는 학생
int lim[1001]; //각 과목의 학생 제한 수
set<int> succ[1001]; //학생당 성공한 과목들

int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin>>lim[i];
	}

	int k;
	for (int i = 1; i <= n; i++) {
		while (1) {
			cin >> k;
			if (k == -1) break;
			sub[k].push_back(i);
		}
	}

	for (int i = 1; i <= m; i++) {
		if (lim[i] >= sub[i].size()) {
			for (int k = 0; k < sub[i].size(); k++) {
				succ[sub[i][k]].insert(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		while (1) {
			cin >> k;
			if (k == -1) break;
			sub[k].push_back(i);
		}
	}

	for (int i = 1; i <= m; i++) {
		if (lim[i] >= sub[i].size()) {
			for (int k = 0; k < sub[i].size(); k++) {
				succ[sub[i][k]].insert(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (succ[i].empty()) cout << "망했어요\n";
		else {
			set<int>::iterator iter;
			for (iter = succ[i].begin(); iter != succ[i].end(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;

		}
	}
}
