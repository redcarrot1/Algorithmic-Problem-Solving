#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int w, h;

//input
void dataInsert(bool map[50][50]) {
	int n;

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			scanf("%d", &n);
			map[i][k] = n;
		}
	}
}

//output
void Out(int num) {
	printf("%d\n", num);
}

//check [y, x] is in or not
bool isInside(int a, int b) {
	return (a >= 0 && a < h) && (b >= 0 && b < w);
}

void bfs(bool map[50][50], int check[50][50], int m, int n) {
	queue<pair<int, int> > q;   //queue for bfs search
	int dx[3] = { -1, 0 ,1 };
	int dy[3] = { -1, 0 ,1 };

	int cur_y = m, cur_x = n;
	q.push(pair<int, int>(cur_y, cur_x));
	check[m][n] = 1;

	while (!q.empty()) {
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				int next_y = cur_y + dx[i];
				int next_x = cur_x + dy[k];

				//next y, x�� �迭 ���ο� �ְ�, check 2�����迭�� ��ϵ��� ����, map�� true�� �Ǿ�������
				if (isInside(next_y, next_x) && check[next_y][next_x] == 0 && map[next_y][next_x] == 1) {
					check[next_y][next_x] = 1; //check�ѰŸ� 1
					q.push(pair<int, int>(next_y, next_x)); //�湮�� �� push push
				}
			}
		}
	}
}

int checkround(bool map[50][50], int check[50][50]) {
	int count = 1;

	for (int m = 0; m < h; m++) {
		for (int n = 0; n < w; n++) {
			if (check[m][n] == 0 && map[m][n] == 1) {
				bfs(map, check, m, n);
				count++;
			}
		}
	}

	return count - 1;
}

int main(void) {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		int check[50][50] = { {0,0}, }; //�����±� ���
		bool map[50][50] = { {0,0}, };  //true - can go, false - can't go

		dataInsert(map);
		Out(checkround(map, check));
	}
}