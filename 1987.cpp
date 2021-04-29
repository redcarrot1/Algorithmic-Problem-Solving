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
	scanf("%1c", &n); //엔터먹는용
	for (int i = 0; i < y_size; i++) {
		for (int j = 0; j < x_size; j++) {
			scanf("%1c", &n);
			map[i][j] = (n - 65);
		}
		scanf("%1c", &n); //엔터먹는용
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
	// 함수에 들어왔으면 -> 방문으로 표시
	visited[map[y][x]] = true;

	// 해당 위치의 주변을 확인
	for (int i = 0; i < 4; i++) {
		int nx = x + movement[i][0];
		int ny = y + movement[i][1];

		// 지도를 벗어나지 않고
		if (0 <= nx && nx < x_size && 0 <= ny && ny < y_size) {
			// 방문하지 않았다면 -> 방문
			if (visited[map[ny][nx]] == false) {
				dfs(nx, ny, numf + 1);
				visited[map[ny][nx]] = false;
				flag = 1;
			}
		}
	}
	if (flag == 0) { //더 이상 방문할곳이 없다면..
		if (num < numf) num = numf;
	}
}

int main() {
	insertData();
	dfs(0, 0, 1);
	printf("%d", num);
}