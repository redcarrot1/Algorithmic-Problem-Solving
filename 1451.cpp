#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > v;
int N, M;

long long sum1(int p, int q) {
	long long a[3] = { 0 };
	long long n;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (k < p) a[0] += v[i][k];
			else if (p <= k && k< q) a[1] += v[i][k];
			else a[2] += v[i][k];
		}
	}
	n = a[0] * a[1] * a[2];
	return n;
	
}

long long sum2(int p, int q) {
	long long a[3] = { 0 };
	long long n;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (i < p) a[0] += v[i][k];
			else if (p <= i && i< q) a[1] += v[i][k];
			else a[2] += v[i][k];
		}
	}
	n = a[0] * a[1] * a[2];
	return n;

}


long long sum(int q, int p) {
	//a[0]: v[0~q-1][0~p-1]
	//a[1]: v[0~q-1][p~m-1]
	//a[2]: v[q~N-1][0~p-1]
	//a[3]: v[q~N-1][p~m-1]
	long long a[4] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			if (i < q && k < p) a[0] += v[i][k];
			else if (i < q && p <= k) a[1] += v[i][k];
			else if (q <= i && k < p) a[2] += v[i][k];
			else if (q <= i && p <= k) a[3] += v[i][k];
		}
	}

	long long vs[4] = { 0 };
	vs[0] = (a[0] + a[1]) * a[2] * a[3];
	vs[1] = (a[0] + a[2]) * a[1] * a[3];
	vs[2] = (a[1] + a[3]) * a[0] * a[2];
	vs[3] = (a[2] + a[3]) * a[0] * a[1];
	long long max = 0;
	for (int i = 0; i < 4; i++) {
		if (max < vs[i]) max = vs[i];
	}
	return max;
}

void inputdata() {
	int c;
	for (int i = 0; i < N; i++) {
		vector<int> element(M);
		v.push_back(element);
	}
	cin.ignore();
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			c = cin.get();
			v[i][k] = c - 48;
		}
		cin.ignore();
	}
}

int main() {
	cin >> N;
	cin >> M;

	inputdata();
	
	/* 배열 확인용
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < M; k++) {
			cout<< v[i][k]<<" ";
		}
		cout << endl;
	}*/
	
	long long totalmax=0;

	//세로로 쪼개기
	for (int p = 1; p < M - 1; p++) {
		for (int q = p + 1; q < M; q++) {
			if (totalmax < sum1(p, q)) totalmax = sum1(p, q);
		}
	}

	//가로로 쪼개기
	for (int p = 1; p < N - 1; p++) {
		for (int q = p + 1; q < N; q++) {
			if (totalmax < sum2(p, q)) totalmax = sum2(p, q);
		}
	}

	for (int q = 1; q <N; q++) {
		for (int p = 1; p < M; p++) {
			if (totalmax < sum(q, p)) totalmax = sum(q, p);
		}
	}

	cout << totalmax;
	
}