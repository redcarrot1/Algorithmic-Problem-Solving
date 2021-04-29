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
	//받는쪽이 수용할 수 있는 물의 양>=주는쪽이 가진 물의 양 -> 전부다 줌
	if (bottle_size[receiver] - bottle[receiver] >= bottle[giver]) {
		bottle[receiver] += bottle[giver];
		bottle[giver] = 0;
	}
	//아니면 줄 수 있는 양까지만 줌
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
        //이미 확인한 무게라면 다음 것 확인
        if (chk[now.a][now.b])
            continue;

        chk[now.a][now.b] = true;

        //첫 번째 물통이 비어 있을 때, 세번째 물통에 담겨 있을 수 있는 물의 양
        //배열의 index로 무게 체크
        if (now.a == 0)
            v.insert(now.c);

        //a->b
        //현재 a에 담겨있는 양 + 현재 b에 담겨있는 양이
        //입력값 B(최대용량)보다 큰 경우 B물통은 최대용량만큼
        //물이 가득채워지게 되고, A물통은 현재 a양 + 현재 b양 - 최대용량만큼
        //물이 남게 된다.
        if (now.a + now.b > bottle_size[1])
            q.push({ (now.a + now.b) - bottle_size[1],bottle_size[1],now.c });

        //현재 a + 현재 b 용량이 B(최대용량)보다 작은 경우
        //A물통에서 물이 전부 옮겨지므로 A는 0
        //B는 현재 a + 현재 b 용량이 된다.
        //C는 변화가 없으므로 현재 용량 now.c를 넣어준다.
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
	// 셋의 모든 원소들을 출력하
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