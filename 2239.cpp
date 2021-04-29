#include <iostream>
#include <stdlib.h>
using namespace std;

int a[9][9]{};

bool checking(int y, int x, int key) {
	//가로 세로 검사
	for (int i = 0; i < 9; i++) {
		if (a[i][x] == key) return false;
		if (a[y][i] == key) return false;
	}

	//9칸 사각형 검사
	int whichsq;
	//어느 사각형인지?
	if (0 <= y && y < 3 && 0 <= x && x < 3) whichsq = 1;
	else if (0 <= y && y < 3 && 3 <= x && x < 6) whichsq = 2;
	else if (0 <= y && y < 3 && 6 <= x && x < 9) whichsq = 3;
	else if (3 <= y && y < 6 && 0 <= x && x < 3) whichsq = 4;
	else if (3 <= y && y < 6 && 3 <= x && x < 6) whichsq = 5;
	else if (3 <= y && y < 6 && 6 <= x && x < 9) whichsq = 6;
	else if (6 <= y && y < 9 && 0 <= x && x < 3) whichsq = 7;
	else if (6 <= y && y < 9 && 3 <= x && x < 6) whichsq = 8;
	else if (6 <= y && y < 9 && 6 <= x && x < 9) whichsq = 9;

	int dy;
	if (1 <= whichsq && whichsq < 4) dy = 0;
	else if (4 <= whichsq && whichsq < 7) dy = 3;
	else if (7 <= whichsq && whichsq <= 9) dy = 6;
	int dx;
	if (whichsq % 3 == 0) dx = 6;
	else if (whichsq % 3 == 1) dx = 0;
	else if (whichsq % 3 == 2) dx = 3;

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (a[dy + i][dx + k] == key) return false;
		}
	}
	return true;
}

void go(int y, int x) {
	//현재 (y, x)을 처리할 차례
	if (y == 9) {
		for (int i = 0; i < 9; i++) {
			for (int k = 0; k < 9; k++) {
				printf("%d", a[i][k]);
			}
			printf("\n");
		}
		exit(0);
	}

	if (a[y][x] != 0) {
		if (x == 8) go(y + 1, 0);
		else go(y, x + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (checking(y, x, i)) {
				a[y][x] = i;
				if (x == 8) go(y + 1, 0);
				else go(y, x + 1);
				a[y][x] = 0;
			}

			if (i == 9) {
				a[y][x] = 0;
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int k = 0; k < 9; k++) {
			scanf("%1d", &a[i][k]);
		}
	}

	go(0, 0);
}