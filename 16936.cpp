#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	long long k;
	vector<pair<int, long long>> v; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		
		int count = 0;
		v.push_back(make_pair(0, k));

		while (k%3==0) {
			k /= 3;
			v[v.size() - 1].first += 1;
		}

		//sort�� first ��������->second �������� ������ ���ĵȴ�.
		//first�� -1�� �������� first�� ��������, second�� ������������ ������ �� �ִ�.
		v[v.size() - 1].first *= -1;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].second << ' ';
	}
}