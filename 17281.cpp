#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int r[50][9]; //r[i][k]=i�̴׿��� k�� ������ ���
//��Ÿ1 2��Ÿ2 3��Ÿ3 Ȩ��4 �ƿ�0
int ans = 0;

void go(int inning, int next, int score, int order[]) {
	if (inning == n) {
		ans = max(ans, score);
		return;
	}
	//���� inning, ���� ����, ����
	int out = 0;
	int gain = 0;
	bool ju[4]{};

	while (1) {
		if (next == 9) next = 0;
		if (out == 3) {
			go(inning + 1, next, score + gain, order);
			return;
		}

		//��Ÿ
		if (r[inning][order[next]] == 1) {
			if (ju[3] == true) {
				gain += 1;
				ju[3] = false;
			}
			if (ju[2] == true) {
				ju[3] = true;
				ju[2] = false;
			}
			if (ju[1] == true) {
				ju[2] = true;
			}
			ju[1] = true;
		}

		//2��Ÿ->2��, 3�� ���� ����, 1�缱��->3��, Ÿ��->2��
		else if (r[inning][order[next]] == 2) {
			if (ju[3] == true) {
				gain += 1;
				ju[3] = false;
			}
			if (ju[2] == true) {
				gain += 1;
				ju[2] = false;
			}
			if (ju[1] == true) {
				ju[3] = true;
				ju[1] = false;
			}
			ju[2] = true;
		}

		//3��Ÿ: 1��, 2��, 3�� ���� ����, Ÿ��->3��
		else if (r[inning][order[next]] == 3) {
			if (ju[3] == true) {
				gain += 1;
				ju[3] = false;
			}
			if (ju[2] == true) {
				gain += 1;
				ju[2] = false;
			}
			if (ju[1] == true) {
				gain += 1;
				ju[1] = false;
			}
			ju[3] = true;
		}

		//Ȩ��
		else if (r[inning][order[next]] == 4) {
			for (int i = 1; i <= 3; i++) {
				if (ju[i] == true) gain += 1;
				ju[i] = false;
			}
			gain += 1;
		}

		//�ƿ�
		else if (r[inning][order[next]] == 0) {
			out += 1;
		}
		next += 1;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < 9; k++) {
			cin >> r[i][k];
		}
	}

	int order[9];
	for (int i = 0; i < 9; i++) {
		order[i] = i;
	}

	do {
		if (order[3] == 0) {
			go(0, 0, 0, order);
		}
	} while (next_permutation(order, order + 9));

	cout << ans;
}