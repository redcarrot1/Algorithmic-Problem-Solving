#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<pair<long long, long long>> v;
int Size;

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void insertData() {
	long long start, end;
	scanf("%d", &Size);
	
	for (int i = 0; i < Size; i++) {
		scanf("%lld %lld", &start, &end);
		v.push_back(make_pair(start, end));
	}
	
	sort(v.begin(), v.begin()+ Size, comp);

	/*È®ÀÎ¿ë
	for (int i = 0; i < Size; i++) {
		printf("%lld %lld\n", v[i].first.first, v[i].first.second);
	}
	*/

}

int main() {
	insertData();

	int n=0, count = 0;
	for (int i = 0; i < Size; i++) {
		if (n <= v[i].first) {
			n = v[i].second;
			count++;
		}
	}
	printf("%d", count);
}