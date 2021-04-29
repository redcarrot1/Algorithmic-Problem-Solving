#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int h, w;
vector< vector<int> > v;
vector<tuple<int, int, int>> cctv; //y x 종류
//1번 4번, 2번 2번, 3번 4번, 4번 4번, 5번 0번

int ans = 64;
int dy[5] = { 0, 0, 0, 1, -1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int one[4] = { 1, 2,3 ,4 };
int four[4][3] = { {1, 2, 3}, {1, 2, 4}, {4, 2, 3}, {1, 4, 3} };
int three[4][2] = { {1, 4}, {1, 3}, {2, 3}, {2, 4} };

//방향 동서남북 1234
void con(int y, int x, int dir, vector<vector<int>>& nv) {
	while (1) {
		if (y < 0 || y >= h || x < 0 || x >= w) return;
		if (nv[y][x] == 6) return;
		nv[y][x] = 9;
		y += dy[dir];
		x += dx[dir];
	}
}

vector<vector<int>> type1(int y, int x, int dir, vector< vector<int> >& v) {
	vector<vector<int>> nv(v);
	con(y, x, dir, nv);
	return nv;
}

vector<vector<int>> type3(int y, int x, int dir, vector< vector<int> >& v) {
	vector<vector<int>> nv(v);

	for (int i = 0; i < 2; i++) {
		con(y, x, three[dir][i], nv);
	}
	return nv;
}

vector<vector<int>> type4(int y, int x, int dir, vector< vector<int> >& v) {
	vector<vector<int>> nv(v);

	for (int i = 0; i < 3; i++) {
		con(y, x, four[dir][i], nv);
	}
	return nv;
}

void go(int cnt, vector< vector<int> >& v) {
	if (cnt == cctv.size()) {
		int temp = 0;
		for (int i = 0; i < h; i++) {
			for (int k = 0; k < w; k++) {
				if (v[i][k] == 0) temp += 1;
			}
		}
		ans = min(ans, temp);
		return;
	}

	//cnt번 cctv를 설정할 차례이다.
	int y, x, type;
	tie(y, x, type) = cctv[cnt];
	if (type == 1) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nv = type1(y, x, one[i], v);
			go(cnt + 1, nv);
		}
	}

	else if (type == 2) {
		vector<vector<int>> nv1(v);
		con(y, x, 1, nv1);
		con(y, x, 2, nv1);
		go(cnt + 1, nv1);

		vector<vector<int>> nv2(v);
		con(y, x, 3, nv2);
		con(y, x, 4, nv2);
		go(cnt + 1, nv2);
	}
	else if (type == 3) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nv = type3(y, x, i, v);
			go(cnt + 1, nv);
		}
	}
	else if (type == 4) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> nv = type4(y, x, i, v);
			go(cnt + 1, nv);
		}
	}
	else if (type == 5) {
		vector<vector<int>> nv1(v);
		con(y, x, 1, nv1);
		con(y, x, 2, nv1);
		con(y, x, 3, nv1);
		con(y, x, 4, nv1);
		go(cnt + 1, nv1);
	}
}

void setData() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		vector<int> element(w);
		v.push_back(element);
	}

	for (int i = 0; i < h; i++) {
		for (int k = 0; k < w; k++) {
			cin >> v[i][k];
			if (v[i][k] != 0 && v[i][k] != 6) {
				cctv.push_back(make_tuple(i, k, v[i][k]));
			}
		}
	}
}
int main() {
	setData();
	go(0, v);
	cout << ans;
}