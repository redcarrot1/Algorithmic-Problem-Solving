#include <stack>
#include <iostream>
using namespace std;
/*
stack<int> st; int�ڷ����� �����ϴ� ���� ����
st.push(4) : ����(4) ����
st.pop() : �� ���� ���� ��
st.top() : �� �� ���� ����
st.empty() : ����ִٸ� 1, �ƴϸ� 0
st.size() : ������ �� ����
40 41
*/

int main() {
	stack<int> st;
	char c;
	int n, pre = 0, count = 0;
	while (1) {
		c = cin.get();
		n = int(c);
		if (n == 10) break;

		if (n == 40) st.push(n);
		else {
			if (pre == 40) {
				st.pop();
				count += st.size();
			}
			else {
				st.pop();
				count++;
			}
		}
		pre = n;
	}
	cout << count;
}