#include <iostream>
#include <string>
#include <algorithm>
#include <cstring> //memset
using namespace std;

string d[101][101]; //n r
int N, M;
string bigNumAdd(string num1, string num2) {
	long long sum = 0;
	string result;
	//1의 자리부터 더하기 시작한다
	while (!num1.empty() || !num2.empty() || sum){
		if (!num1.empty()){
			sum += num1.back() - '0';
			num1.pop_back();
		}

		if (!num2.empty()){
			sum += num2.back() - '0';
			num2.pop_back();
		}

		//다시 string 형태로 만들어 push_back
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	//1의 자리부터 result에 넣었으므로 뒤집어줘야한다
	reverse(result.begin(), result.end());
	return result;
}

string dp(int n, int r) {
	if (n == r || r == 0) return "1";
	if (r == 1) return to_string(n);

	if (d[n][r] != "") return d[n][r];

	d[n][r] = bigNumAdd(dp(n - 1, r - 1), dp(n - 1, r));
	return d[n][r];
}

int main() {
	cin >> N >> M;

	cout << dp(N, M);
}