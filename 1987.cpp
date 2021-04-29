#include <iostream>
#include <vector>
using namespace std;
//57min

int y_size, x_size;
vector< vector<int> > map;

bool visited[26] = { false, };
int movement[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };
int numf = 0;
int num = 0;

void insertData() {
	scanf("%d %d", &y_size, &x_size);
	for (int i = 0; i < y_size; i++) {
		vector<int> element(x_size);
		map.push_back(element);
	}
	char n;
	scanf("%1c", &n); //���͸Դ¿�
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			scanf("%1c", &n);
			map[i][j] = (n - 65);
		}
		scanf("%1c", &n); //���͸Դ¿�
	}
}

void printBoard() {
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

void dfs(int x, int y, int numf) {
	int flag = 0;
	// �Լ��� �������� -> �湮���� ǥ��
	visited[map[y][x]] = true;

	// �ش� ��ġ�� �ֺ��� Ȯ��
	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];

		// ������ ����� �ʰ�
		if (0 <= nx && nx < x_size && 0 <= ny && ny < y_size) {
			// �湮���� �ʾҴٸ� -> �湮
			if (visited[map[ny][nx]] == false) {
				dfs(nx, ny, numf + 1);
				visited[map[ny][nx]] = false;
				flag = 1;
			}
		}
	}
	if (flag == 0) { //�� �̻� �湮�Ұ��� ���ٸ�..
		if (num < numf) num = numf;
	}
}

int main() {
	insertData();
	dfs(0, 0, 1);
	printf("%d", num);
}