#include <iostream>
using namespace std;

int main() {
	int E, S, M, k=0;
	int e, s, m;
	cin >> E;
	cin >> S;
	cin >> M;
	
	for(int k=0; k<7980; k++){
		//15의 배수일 때 나머지는 0임을 주의
		//만약 1+k가 15의 배수라면 15==E를 비교해야함
		e = (1 + k) % 15;
		s = (1 + k) % 28;
		m = (1 + k) % 19;

		if ((1 + k) % 15 == 0) e = 15;
		if ((1 + k) % 28 == 0) s = 28;
		if ((1 + k) % 19 == 0) m = 19;

		if (e == E && s == S && m == M) {
			cout << k + 1;
			break;
		}
	}
}