#include <stack>
#include <iostream>
using namespace std;
/*
stack<int> st; int자료형을 저장하는 스택 생성
st.push(4) : 원소(4) 삽입
st.pop() : 맨 위에 원소 팝
st.top() : 맨 위 원소 리턴
st.empty() : 비어있다면 1, 아니면 0
st.size() : 원소의 수 리턴
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