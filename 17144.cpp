#include <iostream>
#include <queue>
using namespace std;

int a[51][51][2];
int h, w, t, y11=-1, y2;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void insertData() {
	cin >> h >> w >> t;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cin >> a[i][k][0];
			if (a[i][k][0] == -1) {
				if (y11 == -1) {
					y11 = i;
				}
				else {
					y2 = i;
				}
			}
		}
	}
}

void diffusion(int flag) {
	//기존: a[][][flag],  update: a[][][1-flag]
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			a[i][k][1 - flag] = 0;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			int count = 0;
			for (int m = 0; m < 4; m++) {
				int ny = i + dy[m];
				int nx = k + dx[m];

				if (0 > ny || ny >= h || 0 > nx || nx >= w) continue;
				if (a[ny][nx][flag] == -1) continue;

				a[ny][nx][1 - flag] += a[i][k][flag] / 5;
				count += 1;
			}

			a[i][k][1 - flag] += a[i][k][flag] - a[i][k][flag] / 5 * count;
		}
	}
}

void circu(int flag) {
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			a[i][k][1 - flag] = 0;
		}
	}
	//기존: a[][][flag],  update: a[][][1-flag]
	for (int i = 1; i < w - 1; i++) {
		a[y11][i + 1][1 - flag] = a[y11][i][flag];
	}
	for (int i = y11; i - 1 >= 0; i--) {
		a[i - 1][w - 1][1 - flag] = a[i][w - 1][flag];
	}
	for (int i = w - 2; i >= 0; i--) {
		a[0][i][1 - flag] = a[0][i + 1][flag];
	}
	for (int i = 1; i < y11; i++) {
		a[i][0][1 - flag] = a[i - 1][0][flag];
	}


	for (int i = 1; i + 1 <= w - 1; i++) {
		a[y2][i + 1][1 - flag] = a[y2][i][flag];
	}
	for (int i = y2; i + 1 <= h - 1; i++) {
		a[i + 1][w - 1][1 - flag] = a[i][w - 1][flag];
	}
	for (int i = w - 2; i >= 0; i--) {
		a[h - 1][i][1 - flag] = a[h - 1][i + 1][flag];
	}
	for (int i = h - 2; i > y2; i--) {
		a[i][0][1 - flag] = a[i + 1][0][flag];
	}

	for (int i = 1; i < y11; i++) {
		for (int k = 1; k < w - 1; k++) {
			a[i][k][1 - flag] = a[i][k][flag];
		}
	}

	for (int i = y2+1; i < h-1; i++) {
		for (int k = 1; k < w - 1; k++) {
			a[i][k][1 - flag] = a[i][k][flag];
		}
	}
	a[y11][0][1 - flag] = -1;
	a[y2][0][1 - flag] = -1;

}


void print(int flag) {
	cout << "\n====== "<<flag<<" =====\n";
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cout<<a[i][k][flag]<<" ";
		}
		cout << "\n";
	}
	cout << "\n==============\n";
}

int main() {
	insertData();
	int flag = 0;
	while (t>0) {
		diffusion(flag%2);
		flag += 1;
		//print(flag%2);

		circu(flag % 2);
		flag += 1;
		//print(flag%2);

		t -= 1;
	}

	int sum = 0;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			sum+=a[i][k][flag%2];
		}
	}
	cout << sum+2;
}