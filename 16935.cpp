#include <iostream>
using namespace std;

int n, m, r;

void insertData(int a[100][100], int b[100][100]) {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
		}
	}
}

/*
1. 상하반전
2. 좌우반전
3. 오른쪽 90도
4. 왼쪽 90도
5. 부분배열, 시계방향 회전
6. 부분배열, 반시계방향 회전
*/

void operation1(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			b[n - 1 - i][k] = a[i][k];
		}
	}
}

void operation2(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			b[i][m - 1 - k] = a[i][k];
		}
	}
}

void operation3(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			b[k][n - 1 - i] = a[i][k];
		}
	}
}

void operation4(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			b[m - 1 - k][i] = a[i][k];
		}
	}
}

void operation5(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n / 2; i++) {
		for (int k = 0; k < m / 2; k++) {
			b[i][m / 2 + k] = a[i][k];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		for (int k = m / 2; k < m; k++) {
			b[n / 2 + i][k] = a[i][k];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int k = m / 2; k < m; k++) {
			b[i][k - m / 2] = a[i][k];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int k = 0; k < m / 2; k++) {
			b[i - n / 2][k] = a[i][k];
		}
	}
}

void operation6(int a[100][100], int b[100][100]) {
	for (int i = 0; i < n / 2; i++) {
		for (int k = 0; k < m / 2; k++) {
			b[n / 2 + i][k] = a[i][k];
		}
	}

	for (int i = 0; i < n / 2; i++) {
		for (int k = m / 2; k < m; k++) {
			b[i][k - m / 2] = a[i][k];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int k = m / 2; k < m; k++) {
			b[i - n / 2][k] = a[i][k];
		}
	}

	for (int i = n / 2; i < n; i++) {
		for (int k = 0; k < m / 2; k++) {
			b[i][m / 2 + k] = a[i][k];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a[100][100];
	int b[100][100];

	insertData(a, b);

	int swich = 1;
	//1이면 기존배열=a, -1이면 기존배열=b
	while (r--) {
		int op;
		cin >> op;
		if (op == 1) {
			if (swich == 1) operation1(a, b);
			else operation1(b, a);
			swich *= -1;
		}
		else if (op == 2) {
			if (swich == 1) operation2(a, b);
			else operation2(b, a);
			swich *= -1;
		}
		else if (op == 3) {
			if (swich == 1) operation3(a, b);
			else operation3(b, a);
			swich *= -1;
			swap(n, m);
		}
		else if (op == 4) {
			if (swich == 1) operation4(a, b);
			else operation4(b, a);
			swich *= -1;
			swap(n, m);
		}
		else if (op == 5) {
			if (swich == 1) operation5(a, b);
			else operation5(b, a);
			swich *= -1;
		}
		else if (op == 6) {
			if (swich == 1) operation6(a, b);
			else operation6(b, a);
			swich *= -1;
		}
	}

	if (swich == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << b[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	/*
	operation(기존 배열, 신규 배열, 기존배열 세로길이, 기존배열 가로 길이)
	1. 가로, 세로 길이 변경x
	2. 가로, 세로 길이 변경x
	3. 가로, 세로 길이 서로 크로스
	4. 가로, 세로 길이 서로 크로스
	5. 가로, 세로 길이 변경x
	6. 가로, 세로 길이 변경x
	*/
}