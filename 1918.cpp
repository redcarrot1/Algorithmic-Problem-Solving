#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
/*
1. �ǿ����� ��, �빮�� ���ĺ��� ������ ��� ���ڿ��� ��� �߰����ݴϴ�.
2. �������� ���� �Ʒ��� ���� 3���� ��찡 �ֽ��ϴ�.
	i) ��ȣ �ȿ� �ִ� ������ ���� ���� �����ϱ� ������ ���� �ε����� �ִ� �����ڰ� '('��� �ٷ� ���ÿ� �־��ݴϴ�.
	ii) '+', '-', '*', '/' �����ڰ� ������ ��� ���ÿ� ���� �����ں��� �켱������ ���ų� ���� ��ȣ���� ���� ��� ���ڿ��� �߰����ݴϴ�.
		a) '*'�� '/'�� '+'�� '-'���� �켱������ �����ϴ�.
		b) ����, '*'�� '/'�� ������ ���, ������ ��ų� Ȥ�� ������ top�� �켱������ ���� ��ȣ�� ���� ������ ��� ���ڿ��� �߰����ݴϴ�.
		c) '+'�� '-'���� �켱������ ���� ��ȣ�� �����Ƿ� ������ ��ų� ������ top�� ��ȣ�� ������ '('�� ���� ������ ��� ���ڿ��� �߰����ݴϴ�.
	iii) ')'�� ������ ��� ��ȣ�� ���̹Ƿ� ������ top�� '('�� ���� ������ ��� ���ڿ��� �߰����ְ� ���������� '(' ���� pop ���ݴϴ�.

3. �ݺ����� �� ���� ������ ������� ���� ��� ���� �����ڵ��� ��� ���ڿ��� �߰����ݴϴ�
��ó: https://jaimemin.tistory.com/828 [������]
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
		//operand(�ǿ�����)
		if ('A' <= str[i] && str[i] <= 'Z') result += str[i];

		//operator(������)
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
			case '*':
			case '/':
				//�켱���� ���� �����Ƿ� ���� ��ȣ�� pop
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;

			case '+':
			case '-':
				//�켱���� ���ų� ���� ��ȣ�� pop
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.push(str[i]);
				break;

			case ')':
				//'('�� ���� ������ �� pop
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