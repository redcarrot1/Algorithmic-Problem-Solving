#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
1. 피연산자 즉, 대문자 알파벳은 무조건 결과 문자열에 즉시 추가해줍니다.
2. 연산자일 경우는 아래와 같이 3가지 경우가 있습니다.
	i) 괄호 안에 있는 연산을 제일 먼저 실행하기 때문에 현재 인덱스에 있는 연산자가 '('라면 바로 스택에 넣어줍니다.
	ii) '+', '-', '*', '/' 연산자가 등장할 경우 스택에 현재 연산자보다 우선순위가 높거나 같은 기호들은 전부 결과 문자열에 추가해줍니다.
		a) '*'와 '/'가 '+'와 '-'보다 우선순위가 높습니다.
		b) 따라서, '*'와 '/'가 등장할 경우, 스택이 비거나 혹은 스택의 top이 우선순위가 낮은 기호가 나올 때까지 결과 문자열에 추가해줍니다.
		c) '+'와 '-'보다 우선순위가 낮은 기호는 없으므로 스택이 비거나 스택의 top이 괄호의 시작인 '('이 나올 때까지 결과 문자열에 추가해줍니다.
	iii) ')'가 등장할 경우 괄호의 끝이므로 스택의 top이 '('가 나올 때까지 결과 문자열에 추가해주고 마지막으로 '(' 또한 pop 해줍니다.

3. 반복문을 다 돌고도 스택이 비어있지 않은 경우 남은 연산자들을 결과 문자열에 추가해줍니다
출처: https://jaimemin.tistory.com/828 [꾸준함]
*/

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;

	string result;
	stack<char> s;

	for (int i = 0; i < str.length(); i++){
		//operand(피연산자)
		if ('A' <= str[i] && str[i] <= 'Z') result += str[i];

		//operator(연산자)
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				//우선순위 제일 높으므로 같은 기호들 pop
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;

			case '+':
			case '-':
				//우선순위 같거나 높은 기호들 pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;

			case ')':
				//'('가 나올 때까지 다 pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}

				//'(' pop
				s.pop();
				break;
			}
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	cout << result << "\n";
}