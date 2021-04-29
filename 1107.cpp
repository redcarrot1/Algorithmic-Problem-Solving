#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int goal;
vector<int> alive;
int alive_num=0;
int min_diff = 500000;
int g;
void insertData() {
	int broken_num;
	scanf("%d", &goal);
	scanf("%d", &broken_num);

	int n;
	int arr[10] = { 0, };
	for (int i = 0; i < broken_num; i++) {
		scanf("%d", &n);
		arr[n] = 1;
	}
	for (int i = 0; i < 10; i++) {
		if (arr[i] == 0) {
			alive.push_back(i);
		}
	}
	alive_num = 10 - broken_num;
	g = abs(goal - 100);
}

void set(int num) {
	int temp = num;
	int g_length = 1;

	if (num == 0) g_length = 1;
	else {
		while (temp >= 10) {
			temp = temp / 10;
			g_length++;
		}
	}
	min_diff = abs(num - goal);
	//printf("num: %d, g: %d, g_length: %d, min_diff: %d\n",num, g, g_length, min_diff);
	if (min_diff + g_length < g) g = min_diff + g_length;
}

void powcu(int gk, int num) {
	if (gk == -1) {
		//printf("%d를 조사합니다.\n", num);
		set(num);
		return;
	}

	for (int q = 0; q < alive_num; q++) {
		num += pow(10, gk) * alive[q];
		powcu(gk - 1, num);
		num -= pow(10, gk) * alive[q];
	}
}
int main() {
	insertData();
	min_diff = abs(goal - 100);
	for (int i = 0; i <= 6; i++) {
		powcu(i, 0);
	}
	printf("%d", g);
}