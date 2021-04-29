#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

struct Data {
	int a, b, c;
};
	
int bottle_size[3] = { 0, };
int bottle[3] = { 0, };
int list[6][2] = { {0,1}, {0, 2}, {1, 0}, {1,2},{2,0},{2,1} };
set<int> v;
bool chk[202][202];

void pour(int giver, int receiver) {
	//�޴����� ������ �� �ִ� ���� ��>=�ִ����� ���� ���� �� -> ���δ� ��
	if (bottle_size[receiver] - bottle[receiver] >= bottle[giver]) {
		bottle[receiver] += bottle[giver];
		bottle[giver] = 0;
	}
	//�ƴϸ� �� �� �ִ� ������� ��
	else {
		bottle[giver]=bottle[giver]- (bottle_size[receiver] - bottle[receiver]);
		bottle[receiver] = bottle_size[receiver];
	}
}

int check() {
	if (bottle[0] == 0) return 0;
	else return 1;
}

void bfs() {
	queue <Data> q;
	q.push({ 0,0,bottle_size[2] });

	while (!q.empty())
	{
		Data now = q.front();
		q.pop();
        //�̹� Ȯ���� ���Զ�� ���� �� Ȯ��
        if (chk[now.a][now.b])
            continue;

        chk[now.a][now.b] = true;

        //ù ��° ������ ��� ���� ��, ����° ���뿡 ��� ���� �� �ִ� ���� ��
        //�迭�� index�� ���� üũ
        if (now.a == 0)
            v.insert(now.c);

        //a->b
        //���� a�� ����ִ� �� + ���� b�� ����ִ� ����
        //�Է°� B(�ִ�뷮)���� ū ��� B������ �ִ�뷮��ŭ
        //���� ����ä������ �ǰ�, A������ ���� a�� + ���� b�� - �ִ�뷮��ŭ
        //���� ���� �ȴ�.
        if (now.a + now.b > bottle_size[1])
            q.push({ (now.a + now.b) - bottle_size[1],bottle_size[1],now.c });

        //���� a + ���� b �뷮�� B(�ִ�뷮)���� ���� ���
        //A���뿡�� ���� ���� �Ű����Ƿ� A�� 0
        //B�� ���� a + ���� b �뷮�� �ȴ�.
        //C�� ��ȭ�� �����Ƿ� ���� �뷮 now.c�� �־��ش�.
        else
            q.push({ 0,now.a + now.b,now.c });

        //a->c
        if (now.a + now.c > bottle_size[2])
            q.push({ (now.a + now.b) - bottle_size[2],now.b,bottle_size[2] });
        else
            q.push({ 0,now.b,now.a + now.c });

        //b->a
        if (now.b + now.a > bottle_size[0])
            q.push({ bottle_size[0],(now.b + now.a) - bottle_size[0],now.c });
        else
            q.push({ now.b + now.a, 0, now.c });

        //b->c
        if (now.b + now.c > bottle_size[2])
            q.push({ now.a,(now.b + now.c) - bottle_size[2],bottle_size[2] });
        else
            q.push({ now.a, 0, now.b + now.c });

        //c->a
        if (now.c + now.a > bottle_size[0])
            q.push({ bottle_size[0],now.b,(now.c + now.a) - bottle_size[0] });
        else
            q.push({ now.c + now.a,now.b,0 });

        //c->b
        if (now.c + now.b > bottle_size[1])
            q.push({ now.a,bottle_size[1],(now.c + now.b) - bottle_size[1] });
        else
            q.push({ now.a,now.c + now.b,0 });
    }
}


template <typename T>
void print_set(std::set<T>& s) {
	// ���� ��� ���ҵ��� �����
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		cout << *itr << " ";
	}
}

int main() {
	scanf("%d %d %d", &bottle_size[0], &bottle_size[1], &bottle_size[2]);
	bottle[0] = 0;
	bottle[1] = 0;
	bottle[2] = bottle_size[2];

	bfs();



	print_set(v);
}