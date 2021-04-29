#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a, b,n;
vector<int> v;
long long k = 0;

void convert(int i) {
	k+=pow(a, n - i-1) * v[i];
}

int main() {
	cin >> a >> b>> n;

	int c;
	cin.ignore();
	for(int i=0; i<n; i++){
		cin >> c;
		v.push_back(c);
	}

	for (int i = 0; i < v.size(); i++) {
		convert(i);
	}
	v.clear();

	while (1) {
		if (k < b) {
			v.push_back(k);
			break;
		}
		v.push_back(k % b);
		k = k / b;
	}

	for (int i = v.size()-1; i >=0; i--) {
		cout << v[i] << " ";
	}
}