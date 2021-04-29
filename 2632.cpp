#include <iostream>
#include<vector>
using namespace std;

int want;
int num = 0;
int a_size, b_size;
vector<int>a;
vector<int>b;

vector<int>a_ab;
vector<int>b_ab;

void insertData() {
	scanf("%d", &want);
	scanf("%d %d", &a_size, &b_size);

	int n;
	for (int i = 0; i < a_size; i++) {
		scanf("%d", &n);
		a.push_back(n);
	}
	for (int i = 0; i < b_size; i++) {
		scanf("%d", &n);
		b.push_back(n);
	}
}
void sum_a(int i, int k) {
	/*
	i=1 return a[k]
	i=2 return a[k]+a[k+1]
	i=3 return a[k]+a[k+1]+a[k+3] ...
	*/
	int n = 0;
	
	for (int q = 0; q < i; q++) {
		if (k + q >= a_size) {
			n += a[k + q - a_size];
		}
		else n += a[k + q];
		if (n > want) return;
	}
	a_ab.push_back(n);
}
void sum_b(int i, int k) {
	/*
	i=1 return a[k]
	i=2 return a[k]+a[k+1]
	i=3 return a[k]+a[k+1]+a[k+3] ...
	*/
	int n = 0;
	
	for (int q = 0; q < i; q++) {
		if (k + q >= b_size) {
			n += b[k + q - b_size];
		}
		else n += b[k + q];
		if (n > want) return;
	}
	b_ab.push_back(n);
}

void avbil() {
	for (int i = 1; i < a_size; i++) {
		for (int k = 0; k < a_size; k++) {
			sum_a(i, k);
		}
	}
	int n = 0;
	for (int q = 0; q < a_size; q++) {
		n += a[q];
	}
	if (n <= want) a_ab.push_back(n);

}

void bvbil() {
	for (int i = 1; i <b_size; i++) {
		for (int k = 0; k < b_size; k++) {
			sum_b(i, k);
		}
	}
	
	int n = 0;
	for (int q = 0; q < b_size; q++) {
		n += b[q];
	}
	if (n <= want) b_ab.push_back(n);
}

void set() {
	avbil();
	bvbil();
	a_ab.push_back(0);
	b_ab.push_back(0);
	for (int i = 0; i < a_ab.size(); i++) {
		for (int k = 0; k < b_ab.size(); k++) {
			if (a_ab[i] + b_ab[k] == want) num++;
		}
	}
	printf("%d", num);
}

int main() {
	insertData();
	set();
}