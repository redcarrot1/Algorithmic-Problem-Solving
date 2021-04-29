#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[6][8];

void insertData() {
	for (int i = 0; i < 6; i++) {
		cin >> a[i][2] >> a[i][3];
	}
	cin >> a[2][0] >> a[2][1] >> a[3][0] >> a[3][1];
	cin >> a[2][4] >> a[2][5] >> a[3][4] >> a[3][5];
	cin >> a[2][6] >> a[2][7] >> a[3][6] >> a[3][7];
}

int check() {
	if (a[0][2] == a[0][3] && a[0][3]== a[1][2] &&a[1][2]== a[1][3]) {
		if (a[2][2] == a[2][3]&&a[2][3] == a[3][2]&&a[3][2] == a[3][3]) {
			if (a[4][2] == a[4][3] &&a[4][3]== a[5][2]&&a[5][2] == a[5][3]) {
				if (a[2][0] == a[2][1] &&a[2][1]== a[3][0]&&a[3][0] == a[3][1]) {
					if (a[2][4] == a[2][5] &&a[2][5]== a[3][4]&&a[3][4] == a[3][5]) {
						if (a[2][6] == a[2][7]&&a[2][7] == a[3][6]&&a[3][6] == a[3][7])
						{
							return 1;
						} 
					}
				}
			}
		}
	}
	return 0;
}

void turn1(int i) {
	for (int k = 0; k < i; k++) {
		int temp = a[2][4];
		a[2][4] = a[4][3];
		a[4][3] = a[3][1];
		a[3][1] = a[1][2];
		a[1][2] = temp;

		temp = a[3][4];
		a[3][4] = a[4][2];
		a[4][2] = a[2][1];
		a[2][1] = a[1][3];
		a[1][3] = temp;
	}
}

void turn11(int i) {
	for (int k = 0; k < i; k++) {
		int temp = a[2][5];
		a[2][5] = a[5][3];
		a[5][3] = a[3][0];
		a[3][0] = a[0][2];
		a[0][2] = temp;

		temp = a[3][5];
		a[3][5] = a[5][2];
		a[5][2] = a[2][0];
		a[2][0] = a[0][3];
		a[0][3] = temp;
	}
}

void turn2(int i) {
	for (int k = 0; k < i; k++) {
		int temp2 = a[3][0];
		a[3][0] = a[3][6];
		a[3][6] = a[3][4];
		a[3][4] = a[3][2];
		a[3][2] = temp2;

		temp2 = a[3][1];
		a[3][1] = a[3][7];
		a[3][7] = a[3][5];
		a[3][5] = a[3][3];
		a[3][3] = temp2;
	}
}

void turn22(int i) {
	for (int k = 0; k < i; k++) {
		int temp1 = a[2][0];
		a[2][0] = a[2][6];
		a[2][6] = a[2][4];
		a[2][4] = a[2][2];
		a[2][2] = temp1;
		temp1 = a[2][1];
		a[2][1] = a[2][7];
		a[2][7] = a[2][5];
		a[2][5] = a[2][3];
		a[2][3] = temp1;
	}
}

void turn3(int i) {
	for (int k = 0; k < i; k++) {
		int temp2 = a[0][3];
		a[0][3] = a[2][3];
		a[2][3] = a[4][3];
		a[4][3] = a[3][6];
		a[3][6] = temp2;
		temp2 = a[1][3];
		a[1][3] = a[3][3];
		a[3][3] = a[5][3];
		a[5][3] = a[2][6];
		a[2][6] = temp2;
	}
}

void turn33(int i) {
	for (int k = 0; k < i; k++) {
		int temp1 = a[0][2];
		a[0][2] = a[2][2];
		a[2][2] = a[4][2];
		a[4][2] = a[3][7];
		a[3][7] = temp1;
		temp1 = a[1][2];
		a[1][2] = a[3][2];
		a[3][2] = a[5][2];
		a[5][2] = a[2][7];
		a[2][7] = temp1;
	}
}

int main() {
	insertData();

	//1번 돌리고 check. 2번 더 돌리고 check. 1번 더 돌리고 다음거
	int ans = 0;
	turn1(1);
	if (check() == 1) ans = 1;
	turn1(2);
	if (check() == 1) ans = 1;
	turn1(1);

	turn11(1);
	if (check() == 1) ans = 1;
	turn11(2);
	if (check() == 1) ans = 1;
	turn11(1);

	turn2(1);
	if (check() == 1) ans = 1;
	turn2(2);
	if (check() == 1) ans = 1;
	turn2(1);

	turn22(1);
	if (check() == 1) ans = 1;
	turn22(2);
	if (check() == 1) ans = 1;
	turn22(1);

	turn3(1);
	if (check() == 1) ans = 1;
	turn3(2);
	if (check() == 1) ans = 1;
	turn3(1);

	turn33(1);
	if (check() == 1) ans = 1;
	turn33(2);
	if (check() == 1) ans = 1;
	turn33(1);
	cout << ans;
}