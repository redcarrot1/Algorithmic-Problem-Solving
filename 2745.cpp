#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int b, c;
vector<int> v;
long long k = 0;

void convert(int g,int i) {
	k += pow(c, g - i - 1) * v[i];
}

int main() {
	char n;
	while (1) {
		scanf("%1c", &n);
		n = n - '0';
		if (n < 0 || n>9) {
			if (n < 17 || n>42) break;
			else n = n - 7;
		}
		v.push_back(n);
	}
	scanf("%d", &c);
	int g = v.size();

	for (int i = 0; i < v.size(); i++) {
		convert(g, i);
	}
	printf("%d", k);
}