#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

int main() {
	int A, P;
	int po=0;
	string str;
	scanf("%d %d", &A, &P);

	vector<int> v;
	v.push_back(A);
	str = to_string(A);

	while (1) {
		for (int i = 0; i < str.size(); i++) {
			po += pow(str[i]-'0', P);
		}

		for (int i = 0; i < v.size(); i++) {
			if (v[i] == po) {
				printf("%d", i);
				return 0;
			}
		}

		v.push_back(po);
		str = to_string(po);
		po = 0;
	}

	
}