#include <iostream>
using namespace std;

int dice[7];
int map[20][20];
int n, m; //세로 가로
int x, y, k;

void insertData() {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> map[i][k];
		}
	}
}

int main() {
	int move[4][2] = { {0,1}, {0,-1},{-1,0},{1,0} };
	int order;
	insertData();
	while (k--) {
		cin >> order;
		//cout << "현재 위치: " << x << ", " << y;
		int nx = x+move[order - 1][0];
		int ny = y+move[order - 1][1];

		if (0 > nx || nx >= n || 0 > ny || ny >= m) {
			continue;
		}

		if (order == 1) { // right
			int temp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
		}
		else if (order == 2) { // left
			int temp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
		}
		else if (order == 3) { // up
			int temp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
		}
		else { // down
			int temp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
		}

		if (map[nx][ny] == 0) {
			map[nx][ny] = dice[6];
		}
		else {
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[1] << '\n';
		x = nx;
		y = ny;
	}
}