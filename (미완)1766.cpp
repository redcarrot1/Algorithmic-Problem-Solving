#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

string a[32001];
vector<int> v[32001];
int n, k;
int main() {
	cin >> n >> k;
	int x, y;
	for (int i = 0; i < k; i++) {
		//y�� x���� ������ϴ� ��
		cin >> x >> y;
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		a[i] = to_string(i);
		sort(v[i].begin(), v[i].end());
	}


	for (int i = 1; i <= n; i++) {
		if (v[i].size() != 0) {
			//a[v[i].size()-1]�� ���� �ڿ� �ٱ�
			//����������. v[i][v[i].size()-1]
			a[v[i][v[i].size() - 1]].append(" ");
			a[v[i][v[i].size() - 1]].append(a[i]);
			a[i] = "";
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i].size() == 0) continue;
		cout << a[i] << " ";
	}
}