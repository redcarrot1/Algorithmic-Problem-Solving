#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


//�� nxn, k�� ��
int n, k, a[11][11], d[11][11];
vector<int>tree[11][11];
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
/*
��: �ڽ��� ���̸�ŭ ��иԱ�. ����+1, ��� ����->����
����: ���� ���� ������ �������. �� ĭ�� ����/2
����: ���̰� 5�� ����� ������ ����, ������ 8��ĭ�� ���̰�1�� ���� �߰�
�ܿ�: ���� ��� �߰�. a�̿�
*/
void insertData() {
	int m;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <n; k++) {
			cin >> a[i][k];
		}
	}
	int x, y, year;
	for (int i = 0; i < m; i++) {
		cin >> y >> x >> year;
		tree[y - 1][x - 1].push_back(year);
	}
}

void sortage() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			sort(tree[i][k].begin(), tree[i][k].end());
		}
	}
}

void spring_summer() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {

			for (int j = 0; j < tree[i][k].size(); j++) {
				//����� ���ڸ�.. ����->�� ĭ�� ��лѸ���
				if (d[i][k] < tree[i][k][j]) {
					
					for (int z = j; z < tree[i][k].size(); z++) {
						d[i][k] += tree[i][k][z] / 2;
					}
					tree[i][k].erase(tree[i][k].begin()+j, tree[i][k].begin()+tree[i][k].size());
					break;
				}

				else{
					d[i][k] -= tree[i][k][j];
					tree[i][k][j] += 1;
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			d[i][k] += a[i][k];
		}
	}
}

void fall() {
	int plus[11][11]{};
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < tree[i][k].size(); j++) {
				if (tree[i][k][j] % 5 == 0) {

					for (int q = 0; q < 8; q++) {
						int ny = i + dy[q];
						int nx = k + dx[q];

						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						plus[ny][nx] += 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			for (int j = 0; j < plus[i][k]; j++) {
				tree[i][k].push_back(1);
			}
		}
	}

}
int main() {

	insertData();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			d[i][k] = 5;
		}
	}
	for (int i = 0; i < k; i++) {
		sortage();
		spring_summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			ans += tree[i][k].size();
		}
	}
	cout << ans;
}