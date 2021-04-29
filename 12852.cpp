#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

//bfs+dp; bfs�� ���� ���� ���+dp�� ����Ƚ�� ���̱�

int n;
int d[1000001]{};
string sd[1000001]{};


void bfs() {
	queue<tuple<int, int, string>> q; // <���� ����, ����Ƚ��, �������>
	q.push(make_tuple(n, 0, to_string(n)));
	d[n] = 0;
	sd[n] = "";

	while (!q.empty()) {
		int nx, cnt;
		string op;
		tie(nx, cnt, op) = q.front();
		q.pop();

		if (nx == 1) {
			cout << d[1] << "\n" << sd[1];
			return;
		}
		
		if (nx % 3 == 0) {
			//���� ������ �ȵǾ��ٸ�
			if (d[nx / 3] == 0) {
				d[nx / 3] = cnt + 1;
				sd[nx / 3] = op + " " + to_string(nx / 3);
				q.push(make_tuple(nx / 3, cnt + 1, sd[nx / 3]));
			}
		}

		if (nx % 2 == 0) {
			//���� ������ �ȵǾ��ٸ�
			if (d[nx / 2] == 0) {
				d[nx / 2] = cnt + 1;
				sd[nx / 2] = op + " " + to_string(nx / 2);
				q.push(make_tuple(nx / 2, cnt + 1, sd[nx / 2]));
			}
		}

		if (nx >1) {
			//���� ������ �ȵǾ��ٸ�
			if (d[nx -1] == 0) {
				d[nx -1] = cnt + 1;
				sd[nx -1] = op + " " + to_string(nx -1);
				q.push(make_tuple(nx -1, cnt + 1, sd[nx -1]));
			}
		}
	}

}

int main() {
	cin >> n;
	if (n == 1) {
		cout << "0\n1";
		return 0;
	}
	bfs();
}