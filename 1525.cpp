#include <iostream>
#include <set>
#include <queue>
#include <string>
using namespace std;
string str;
queue<string>q;
set<string>s;
int Move[4] = { -1, 1, -3, 3 }; //�� �� �� ��
int num = 0;
bool flag=true;

void bfs() {
	int a;
	while (!q.empty()) {

		int len = q.size();
		for (int j = 0; j < len; j++) {

			if (q.front() == "123456780") {
				flag = false;
				return;
			}

			for (int i = 0; i < 9; i++) {
				if ((q.front())[i] == '0') {
					a = i;
					break;
				}
			}

			for (int i = 0; i < 4; i++) {
				int x = a + Move[i];

				if (x < 0 || (a % 3 == 0 && i == 0) || (a % 3 == 2 && i == 1) || x >= 9) // ������ ��� ���� 
					continue;

				else {
					string cp = q.front(); //���ڿ� swap 
					swap(cp[x], cp[a]);
					if (s.count(cp) == 0) {
						s.insert(cp);
						q.push(cp);
					}
				}
			}

			q.pop();
		}
		num++;
	}
}

int main() {
	int n;
	string sr;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &n);
		sr = to_string(n);
		str.append(sr);
	}
	q.push(str);

	int a;
	q.push(str);
	s.insert(str);

	bfs();
	if (flag) //flag�� true�̸� ���ڿ��� �ϼ����� ���Ѱ�� 
		printf("-1");
	else
		printf("%d", num);
}