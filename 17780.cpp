#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct user {
	int num = 0;
	int x = 0;
	int y = 0;
	int dir = 0; //0���� ������� ��, ��, ��, ��
}user;

typedef struct buser {
	vector<int> st; //�׿��ִ� �� ��ȣ. �տ������Ͱ� �� �Ʒ�
}buser;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int board[13][13];//��0 ��1 ��2
int n, k; //�� ũ��. ���� ����
user u[11]; //u[i]=i�� ��
buser bu[13][13]; //bu[i][k]=(i, j)�� �����ִ� ��

/*
����� ��쿡�� �� ĭ���� �̵��Ѵ�. �̵��Ϸ��� ĭ�� ���� �̹� �ִ� ��쿡�� ���� ���� A�� ���� �÷����´�.
A�� ���� ���� �ٸ� ���� �ִ� ��쿡�� A�� ���� ���� �ִ� ��� ���� �̵��Ѵ�.

�������� ��쿡�� �̵��� �Ŀ� A�� ���� �� ���� �ִ� ��� ���� �׿��ִ� ������ �ݴ�� �ٲ۴�.

�Ķ����� ��쿡�� A�� ���� �̵� ������ �ݴ�� �ϰ� �� ĭ �̵��Ѵ�. ������ �ݴ�� �� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ���⸸ �ݴ�� �ٲ۴�.

ü������ ����� ��쿡�� �Ķ����� ���� ����̴�.
*/

void white(int ny, int nx, int q) {
	//q�� ���� ��������.

	//�̵� ���� ���� ��ġ
	int oy = u[q].y;
	int ox = u[q].x;

	for (int i = 0; i < bu[oy][ox].st.size(); i++) {
		bu[ny][nx].st.push_back(bu[oy][ox].st[i]);
		u[bu[oy][ox].st[i]].x = nx;
		u[bu[oy][ox].st[i]].y = ny;
	}
	bu[oy][ox].st.clear();
	u[q].x = nx;
	u[q].y = ny;
}

void red(int ny, int nx, int q) {
	//q�� ���� ��������.

	//�̵� ���� ���� ��ġ
	int oy = u[q].y;
	int ox = u[q].x;
	reverse(bu[oy][ox].st.begin(), bu[oy][ox].st.end());
	for (int i = 0; i < bu[oy][ox].st.size(); i++) {
		bu[ny][nx].st.push_back(bu[oy][ox].st[i]);
		u[bu[oy][ox].st[i]].x = nx;
		u[bu[oy][ox].st[i]].y = ny;
	}
	bu[oy][ox].st.clear();
	u[q].x = nx;
	u[q].y = ny;
}

void redir(int q) {
	if (u[q].dir == 0) u[q].dir = 1;
	else if (u[q].dir == 1) u[q].dir = 0;
	else if (u[q].dir == 2) u[q].dir = 3;
	else if (u[q].dir == 3) u[q].dir = 2;
}

int blue(int q) {
	int zy = u[q].y - dy[u[q].dir];
	int zx = u[q].x - dx[u[q].dir];

	if (zy < 0 || zy >= n || zx < 0 || zx >= n) {
		redir(q);
		return 0;
	}
	else if (board[zy][zx] == 2) {
		redir(q);
		return 0;
	}
	else {
		redir(q);
		return -1;
	}
}

int check() {
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (bu[i][k].st.size() >= 4) {
				return -1;
			}
		}
	}
	return 1;
}

void insertdata() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> board[i][k];
		}
	}
	int x, y, d;
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> d;
		x -= 1; y -= 1;
		u[i].dir = d-1;
		u[i].x = x;
		u[i].y = y;
		u[i].num = i;

		bu[y][x].st.push_back(i);
	}
}

int main() {
	insertdata();
	int ans = 0;
	while (check()!=-1) {
		if (ans > 1000) {
			cout << "-1";
			return 0;
		}
		for (int i = 0; i < k; i++) {
			//i�� ���� ����������
			if (bu[u[i].y][u[i].x].st[0] != i) continue;

			int ny = u[i].y + dy[u[i].dir];
			int nx = u[i].x + dx[u[i].dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
				i += blue(i);
			}
			else if (board[ny][nx] == 0) {
				white(ny, nx, i);
			}
			else if (board[ny][nx] == 1) {
				red(ny, nx, i);
			}
			else {
				i += blue(i);
			}
		}
		ans += 1;
	}
	cout << ans;
}