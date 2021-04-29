#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> v;

typedef struct foot {
	int l;
	int r;
	int cost;
}foot;

foot a[100000][2]; //�� ��
//���� ���� ������ �ִ� ���� ������� �ʴ� ���̴�.
//�߾ӿ� �ִ� ���� �ٸ� �������� ������ ��, 2�� ���� ���
//�ٸ� �������� ������ �������� ������ ���� 3
//�ݴ������� �����϶��� 4��
//���� ���� ������ �ѹ� �� �����ٸ�, �׶��� 1�� ��

tuple<int, int, int> leftToleft(int i) {
	//d[i-1][0]���� d[i][0]���� �̵��ϴ� ��� <�޹� ��ġ, ������ ��ġ, cost>
	//�� ���� �ϳ��� ���� ���ǿ� �̹� �÷����ִٸ� ���ñ��� ����.
	int l = a[i - 1][0].l;
	int r = a[i - 1][0].r;
	int cost, nl, nr;
	int nn = v[i];

	if (r == nn) {
		//�̹� �������� �ö��ִٸ� �޹߷δ� i��° ������ ������
		return tuple(l, r, -1);
	}
	else if (l == nn) {
		return tuple(l, r, 1);
	}

	//�޹��̵�
	if (l == 0) {
		nl = v[i];
		cost = 2;
	}
	else if ((abs(l - v[i])) % 2 == 0) {
		nl = v[i];
		cost = 4;
	}
	else if ((abs(l - v[i])) % 2 == 1) {
		nl = v[i];
		cost = 3;
	}
	return tuple(nl, r, cost);
}

tuple<int, int, int> leftToright(int i) {
	//d[i-1][0]���� d[i][0]���� �̵��ϴ� ��� <�޹� ��ġ, ������ ��ġ, cost>
	//�� ���� �ϳ��� ���� ���ǿ� �̹� �÷����ִٸ� ���ñ��� ����.
	int l = a[i - 1][0].l;
	int r = a[i - 1][0].r;
	int cost, nl, nr;
	int nn = v[i];

	if (l == nn) {
		//�̹� �޹��� �ö��ִٸ� �����߷δ� i��° ������ ������
		return tuple(l, r, -1);
	}
	else if (r == nn) {
		return tuple(l, r, 1);
	}

	//�������̵�
	if (r == 0) {
		nr = v[i];
		cost = 2;
	}
	else if ((abs(r - v[i])) % 2 == 0) {
		nr = v[i];
		cost = 4;
	}
	else if ((abs(r - v[i])) % 2 == 1) {
		nr = v[i];
		cost = 3;
	}
	return tuple(l, nr, cost);
}


tuple<int, int, int> rightToleft(int i) {
	//d[i-1][0]���� d[i][0]���� �̵��ϴ� ��� <�޹� ��ġ, ������ ��ġ, cost>
	//�� ���� �ϳ��� ���� ���ǿ� �̹� �÷����ִٸ� ���ñ��� ����.
	int l = a[i - 1][1].l;
	int r = a[i - 1][1].r;
	int cost, nl, nr;
	int nn = v[i];

	if (r == nn) {
		//�̹� �������� �ö��ִٸ� �޹߷δ� i��° ������ ������
		return tuple(l, r, -1);
	}
	else if (l == nn) {
		return tuple(l, r, 1);
	}

	//�޹��̵�
	if (l == 0) {
		nl = v[i];
		cost = 2;
	}
	else if ((abs(l - v[i])) % 2 == 0) {
		nl = v[i];
		cost = 4;
	}
	else if ((abs(l - v[i])) % 2 == 1) {
		nl = v[i];
		cost = 3;
	}
	return tuple(nl, r, cost);
}

tuple<int, int, int> rightToright(int i) {
	//d[i-1][0]���� d[i][0]���� �̵��ϴ� ��� <�޹� ��ġ, ������ ��ġ, cost>
	//�� ���� �ϳ��� ���� ���ǿ� �̹� �÷����ִٸ� ���ñ��� ����.
	int l = a[i - 1][1].l;
	int r = a[i - 1][1].r;
	int cost, nl, nr;
	int nn = v[i];

	if (l == nn) {
		//�̹� �޹��� �ö��ִٸ� �����߷δ� i��° ������ ������
		return tuple(l, r, -1);
	}
	else if (r == nn) {
		return tuple(l, r, 1);
	}

	//�������̵�
	if (r == 0) {
		nr = v[i];
		cost = 2;
	}
	else if ((abs(r - v[i])) % 2 == 0) {
		nr = v[i];
		cost = 4;
	}
	else if ((abs(r - v[i])) % 2 == 1) {
		nr = v[i];
		cost = 3;
	}
	return tuple(l, nr, cost);
}

void setData() {
	int k;
	v.push_back(0);
	while (1) {
		cin >> k;
		if (k == 0) break;
		v.push_back(k);
	}
}


int main() {
	setData();

	a[0][0].l = 0;
	a[0][0].r = 0;
	a[0][0].cost = 0;

	a[0][1].l = 0;
	a[0][1].r = 0;
	a[0][1].cost = 0;

	a[1][0].l = v[1];
	a[1][0].r = 0;
	a[1][0].cost = 2;

	a[1][1].l = 0;
	a[1][1].r = v[1];
	a[1][1].cost = 2;

	for (int i = 1; i < v.size()-1; i++) {
		int nl1, nr1, cost1;
		int nl2, nr2, cost2;
		int nl3, nr3, cost3;
		int nl4, nr4, cost4;

		tie(nl1, nr1, cost1) = leftToleft(i);
		tie(nl2, nr2, cost2) = leftToright(i);
		tie(nl3, nr3, cost3) = rightToleft(i);
		tie(nl4, nr4, cost4) = rightToright(i);
		
		if (cost1 == -1 || cost3 == -1) {

		}
		if ((a[i - 1][0].cost + cost1) > (a[i - 1][1].cost + cost3)) {
			a[i][0].l = nl3;
			a[i][0].r = nr3;
			a[i][0].cost = a[i - 1][1].cost + cost3;
		}
		else {
			a[i][0].l = nl1;
			a[i][0].r = nr1;
			a[i][0].cost = a[i - 1][0].cost + cost1;
		}

		if ((a[i - 1][0].cost + cost2) > (a[i - 1][1].cost + cost4)) {
			a[i][1].l = nl2;
			a[i][1].r = nr2;
			a[i][1].cost = a[i - 1][1].cost + cost2;
		}
		else {
			a[i][1].l = nl4;
			a[i][1].r = nr4;
			a[i][1].cost = a[i - 1][0].cost + cost4;
		}		
	}

	cout << min(a[v.size()-2][0].cost, a[v.size()-2][1].cost);

	

}