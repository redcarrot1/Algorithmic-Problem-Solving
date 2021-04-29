#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n;
vector<int> num;
vector<int> op; //+ 0, - 1, * 2;

int cc(int num1, int num2, int op) {
	if (op == 0) return num1 + num2;
	else if (op == 1) return num1 - num2;
	else return num1 * num2;
}

int c(vector<bool>& temp) {
	queue<int> numv;
	queue<int> opv;
	int t = num[0];

	for (int i = 0; i < (n - 1) / 2; ++i) {
		//(i번 숫자) (i번 연산) i+1연산
		if (temp[i] == true || op[i] == 2) {
			t = cc(t, num[i + 1], op[i]);
			//i += 1;
		}
		else {
			numv.push(t);
			opv.push(op[i]);
			t = num[i+1];
		}
	}
	int sum = numv.front();
	numv.pop();
	while (!numv.empty() && !opv.empty()) {
		sum = cc(sum, numv.front(), opv.front());
		numv.pop();
		opv.pop();
	}
	sum = cc(sum, t, opv.front());
	return sum;
}

void insertData() {
	scanf("%d", &n);
	char a, b;
	scanf("%c", &a); //enter먹는용
	for (int i = 0; i < n / 2; i++) {
		scanf("%c", &a);
		scanf("%c", &b);
		num.push_back(a - '0');
		if (b == '+') op.push_back(0);
		else if (b == '-') op.push_back(1);
		else op.push_back(2);
	}
	scanf("%c", &a);
	num.push_back(a - '0');
}

int main() {
	insertData();
	vector<bool> temp((n - 1) / 2);

	temp[0] = true;
	temp[3] = true;
	/*for (int i = 0; i < 0; i++) {
		temp[i] = true;
	}*/
	cout<<c(temp);
}