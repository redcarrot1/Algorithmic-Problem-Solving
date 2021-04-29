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

	sort(Plus, Plus + countP, comp); //양수는 내림차순 정렬
	sort(mius, mius + countM); //음수는 오름차순 정렬


	long long sum=0;
	for (int i = 0; i < countP; i+=2) { //양수는 서로 무조건 곱함
		if (i + 1 > countP - 1) break;
		else sum += Plus[i] * Plus[i + 1];
	}
	if (countP % 2 != 0) sum += Plus[countP-1]; //홀수개면 나머지 하나는 그냥 더하기


	for (int i = 0; i < countM; i += 2) { //음수도 무조건 곱함
		if (i + 1 > countM - 1) break;
		sum += mius[i] * mius[i + 1];
	}
	if (countM % 2 != 0) { //홀수개 && 0이 한개라도 있으면 0 곱해서 없애주기, 0이 없으면 어쩔 수 없이 더해주기
		if (zeroNum == 0) sum += mius[countM - 1];
	}

	sum += oneNum; //1은 누구와 곱해도 손해. 그냥 더하는게 이득이다.
	printf("%d", sum);
}