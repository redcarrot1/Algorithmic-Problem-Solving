#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define x_size 9
#define y_size 9
//�������ɸ� �� 3�ð�? �ٸ� ��� �ڵ嵵 ���� �����ϰ�..
//������� ��Ʈ��ŷ �����Ҷ� ���ø��� ����Լ��� ��������..
vector< vector<int> > map;
vector<pair<int, int>> zero;

void insertData() {
	for (int i = 0; i < y_size; i++) {
		vector<int> element(x_size);
		map.push_back(element);
	}

	int n;
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			scanf("%d", &n);
			map[i][j] = n;
			if (n == 0) zero.push_back(make_pair(i, j));
		}
	}

	/*for (int i = 0; i <zero.size(); i++) {
		printf("y: %d, x: %d\n", zero[i].first, zero[i].second);
	}*/
}

bool checking(int y, int x, int key) {
	//���� ���� �˻�
	for (int i = 0; i < 9; i++) {
		if (map[i][x] == key) return false;
		if (map[y][i] == key) return false;
	}

	//9ĭ �簢�� �˻�
	int whichsq;
	//��� �簢������?
	if (0 <= y && y < 3 && 0 <= x && x < 3) whichsq = 1;
	else if (0 <= y && y < 3 && 3 <= x && x < 6) whichsq = 2;
	else if (0 <= y && y < 3 && 6 <= x && x < 9) whichsq = 3;
	else if (3 <= y && y < 6 && 0 <= x && x < 3) whichsq = 4;
	else if (3 <= y && y < 6 && 3 <= x && x < 6) whichsq = 5;
	else if (3 <= y && y < 6 && 6 <= x && x < 9) whichsq = 6;
	else if (6 <= y && y < 9 && 0 <= x && x < 3) whichsq = 7;
	else if (6 <= y && y < 9 && 3 <= x && x < 6) whichsq = 8;
	else if (6 <= y && y < 9 && 6 <= x && x < 9) whichsq = 9;
	else printf("�߸��������Դϴ�.\n");

	int dy;
	if (1 <= whichsq && whichsq < 4) dy = 0;
	else if (4 <= whichsq && whichsq < 7) dy = 3;
	else if (7 <= whichsq && whichsq <= 9) dy = 6;
	int dx;
	if (whichsq % 3 == 0) dx = 6;
	else if (whichsq % 3 == 1) dx = 0;
	else if (whichsq % 3 == 2) dx = 3;
	else printf("�߸��������Դϴ�.\n");

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (map[dy + i][dx + k] == key) return false;
		}
	}
	return true;
}

void Print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int cdx) {
	if (cdx == zero.size()) {
		Print();
		exit(0);
	}

	//printf("cdx: %d\n", cdx);
	//printf("\n===================\n");
	//Print();
	//printf("\n===================\n");

	int dy = zero[cdx].first;
	int dx = zero[cdx].second;

	for (int i = 1; i <= 9; i++) {
		if (checking(dy, dx, i)) {
			map[dy][dx] = i;
			//printf("y:%d x:%d �� %d�� �ֽ��ϴ�.\n", dy, dx, i);
			dfs(cdx + 1);
			//printf("y:%d x:%d �� %d�� ���ϴ�.\n", dy, dx, i);
			map[dy][dx] = 0;
		}
	}
}

int main() {
	insertData();
	dfs(0);
}