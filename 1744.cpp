#include <iostream>
#include <algorithm>
using namespace std;

int Plus[10000] = { 0, };
int mius[10000] = { 0, };
int oneNum = 0;
int zeroNum = 0;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	int n, countP=0, countM=0;
	int k;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k < 0) {
			mius[countM] = k;
			countM++;
		}
		else if (k > 1) {
			Plus[countP] = k;
			countP++;
		}
		else if (k == 0) zeroNum++;
		else if (k == 1) oneNum++;
	}

	sort(Plus, Plus + countP, comp); //����� �������� ����
	sort(mius, mius + countM); //������ �������� ����


	long long sum=0;
	for (int i = 0; i < countP; i+=2) { //����� ���� ������ ����
		if (i + 1 > countP - 1) break;
		else sum += Plus[i] * Plus[i + 1];
	}
	if (countP % 2 != 0) sum += Plus[countP-1]; //Ȧ������ ������ �ϳ��� �׳� ���ϱ�


	for (int i = 0; i < countM; i += 2) { //������ ������ ����
		if (i + 1 > countM - 1) break;
		sum += mius[i] * mius[i + 1];
	}
	if (countM % 2 != 0) { //Ȧ���� && 0�� �Ѱ��� ������ 0 ���ؼ� �����ֱ�, 0�� ������ ��¿ �� ���� �����ֱ�
		if (zeroNum == 0) sum += mius[countM - 1];
	}

	sum += oneNum; //1�� ������ ���ص� ����. �׳� ���ϴ°� �̵��̴�.
	printf("%d", sum);
}