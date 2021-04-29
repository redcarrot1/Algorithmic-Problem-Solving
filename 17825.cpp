#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> board[6];
int dia[10];
int player[4][2]{};
int ans = 0;

void setting() {
	vector<int> a(21); //0
	vector<int> ten = { 10, 13, 16,19, -5 }; //-1
	vector<int> twn = { 20, 22, 24,-5 }; //-2
	vector<int> tre = { 30,28,27,26,-5 }; //-3
	vector<int> fin = { 40, 0 };  //-4
	vector<int> tf = { 25, 30,35,-4 }; //-5

	for (int i = 0; i < 21; i++) {
		a[i] = 2 * i;
	}
	a[0] = -100;
	a[5] = -1;
	a[10] = -2;
	a[15] = -3;
	a[20] = -4;

	board[0] = a;
	board[1] = ten;
	board[2] = twn;
	board[3] = tre;
	board[4] = fin;
	board[5] = tf;

	for (int i = 0; i < 10; i++) {
		cin >> dia[i];
	}
}

pair<int, int> movesm(int p, int how) {
	//p번 플레이어가 how칸 이동하면 어디야?

	//현재위치
	int cntBoard = player[p][0];
	int cntnum = player[p][1];

	//한칸씩 나가보자
	for (int i = 0; i < how; i++) {
		cntnum += 1;

		int k = board[cntBoard][cntnum];
		if (k == -4 || k == -5) {
			cntBoard = -k;
			cntnum = 0;
		}
		else if (k == 0) return make_pair(4, 1);
	}

	//마지막 도착칸이 파랑칸이라면?
	if (board[cntBoard][cntnum] < 0) {
		cntBoard = -board[cntBoard][cntnum];
		cntnum = 0;
	}

	return make_pair(cntBoard, cntnum);
}

bool canmove(int newBoard, int newnum) {
	if (newBoard == 4 && newnum == 1) return true;
	for (int i = 0; i < 4; i++) {
		if (player[i][0] == newBoard && player[i][1] == newnum) return false;
	}
	return true;
}

void go(int cnt, int sum) {
	if (cnt == 10) {
		if (ans < sum) ans = sum;
		return;
	}

	int newBoard, newnum, nowBoard, nownum;
	for (int i = 0; i < 4; i++) {
		nowBoard = player[i][0];
		nownum = player[i][1];

		if (nowBoard == 4 && nownum == 1) continue;

		//출발선에서 시작하는 플레이어가 있으면, 그 이후 플레이어는 이동하지 않아도 된다.
		tie(newBoard, newnum) = movesm(i, dia[cnt]);
		if (canmove(newBoard, newnum)) {
			player[i][0] = newBoard;
			player[i][1] = newnum;
			go(cnt + 1, sum + board[newBoard][newnum]);
			player[i][0] = nowBoard;
			player[i][1] = nownum;
			if (nowBoard == 0 && nownum == 0) break;
		}
	}
}

int main() {
	setting();
	go(0, 0);
	cout << ans;
}