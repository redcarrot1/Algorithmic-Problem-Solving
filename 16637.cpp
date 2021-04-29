#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> num;
vector<int> op; //+ 0, - 1, * 2;
int ans = -2147483646;

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

int cc(int num1, int num2, int op) {
	if (op == 0) return num1 + num2;
	else if (op == 1) return num1 - num2;
	else return num1 * num2;
}

void comb(int r) {
	vector<bool> temp((n - 1) / 2);
	for (int i = 0; i < r; i++)
		temp[i] = true;

	do {
		vector<int> numv(num);
		vector<int> opv(op);
		int flag = 0;
		for (int i = 0; i < (n - 1) / 2; ++i) {
			if (i != 0) {
				if (temp[i] == true && temp[i - 1] == true) {
					flag = 1;
					break;
				}
			}
			if (temp[i]) {
				//i번째 op가 먼저 계산 -> (i번 숫자) (i번 op) (i+1번 숫자)

				int num1 = numv[i];
				int num2 = numv[i + 1];
				int operation = opv[i];
				int k = cc(num1, num2, operation);

				numv[i] = k;
				opv[i] = 0;
				numv[i + 1] = 0;
			}
		}

		if (flag == 1) continue;
		int temp = numv[0];
		for (int i = 0; i < (n - 1) / 2; i++) {
			temp = cc(temp, numv[i + 1], opv[i]);
		}
		ans = max(ans, temp);

		/*
			for (int i = 0; i < numv.size(); i++) {
				cout << numv[i] << " ";
				if (i == numv.size() - 1) break;
				if (opv[i] == 0) cout << "+ ";
				else if (opv[i] == 1) cout << "- ";
				else  cout << "* ";
			}
			cout << "\n\n";
		}
		*/
	} while (prev_permutation(temp.begin(), temp.end()));
}

int main() {
	insertData();
	for (int i = 0; i <= (n + 1) / 4; i++) {
		comb(i);
	}
	cout << ans;
}