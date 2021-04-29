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

		//sort는 first 오름차순->second 오름차순 순서로 정렬된다.
		//first에 -1을 곱함으로 first는 내림차순, second은 오름차순으로 정렬할 수 있다.
		v[v.size() - 1].first *= -1;
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i].second << ' ';
	}
}