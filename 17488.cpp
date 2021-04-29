#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> sub[1001]; //���� ���� �л�
int lim[1001]; //�� ������ �л� ���� ��
set<int> succ[1001]; //�л��� ������ �����

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
		if (succ[i].empty()) cout << "���߾��\n";
		else {
			set<int>::iterator iter;
			for (iter = succ[i].begin(); iter != succ[i].end(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;

		}
	}
}
