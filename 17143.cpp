#include <iostream>
#include <string>
using namespace std;

/*
���ÿ��� ���������� �� ĭ �̵��Ѵ�.
���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
�� �̵��Ѵ�.
*/

typedef struct sha {
	int speed = -1; //speed=-1�̸� �� ĭ���� ���°Ŵ�.
	int dir = -1; //1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4�� ���� ����
	int size = -1;
}sha;

sha a[101][101];
sha temp[101][101];

int h, w, person = -1;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int fishing() {
	for (int i = 0; i < h; i++) {
		if (a[i][person].speed != -1) {
			a[i][person].speed = -1;
			return a[i][person].size;
		}
	}
	return 0;
}

void move() {
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			temp[i][k].speed = -1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if (a[i][k].speed == -1) continue;

			int direction = a[i][k].dir;
			int x = i;
			int y = k;
			for (int q = 0; q < a[i][k].speed; q++) {
				if (direction == 0) { // up
					if (x == 0) {
						x = 1;
						direction = 1;
					}
					else {
						x -= 1;
					}
				}
				else if (direction == 1) { // down
					if (x == h - 1) {
						x = h - 2;
						direction = 0;
					}
					else {
						x += 1;
					}
				}
				else if (direction == 2) { // right
					if (y == w - 1) {
						y = w - 2;
						direction = 3;
					}
					else {
						y += 1;
					}
				}
				else if (direction == 3) { // left
					if (y == 0) {
						y = 1;
						direction = 2;
					}
					else {
						y -= 1;
					}
				}
			}
			a[i][k].dir = direction;
			if (temp[x][y].speed != -1) {
				if (temp[x][y].size < a[i][k].size) temp[x][y] = a[i][k];
			}
			else {
				temp[x][y] = a[i][k];
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			a[i][k] = temp[i][k];
		}
	}
}

void print() {
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			if (a[i][k].speed == -1) {
				cout << "0 ";
			}
			else cout << "1 ";
		}
		cout << "\n";
	}
}

void insertData() {
	int m, x, y;
	cin >> h >> w >> m;
	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			a[i][k].speed = -1;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		y -= 1; x -= 1;
		cin >> a[y][x].speed >> a[y][x].dir >> a[y][x].size;
		a[y][x].dir -= 1;
	}
}

int main() {
	insertData();
	long long ans = 0;
	for (int i = 0; i < w; i++) {
		person += 1;
		//cout << "\n=======" << person << "========\n";
		ans += fishing();
		move();
		//print();
		//cout << ans << "=====\n";
	}
	cout << ans;
}