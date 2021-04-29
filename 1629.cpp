#include <iostream>
using namespace std;
int c;

long long odd(long long a, long long b);

long long even(long long a, long long b) {
	if (b == 1) return a % c;
	else if (b == 0) return 1;
	else if (b % 2 == 1) return odd(a, b);
	else {
		long long k=even(a, b / 2)%c;
		return (k*k)%c;
	}
}

long long odd(long long a, long long b) {
	return (a%c * even(a, b-1)) % c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b;
	cin >> a >> b >> c;
	
	if (b == 0) cout << 1 % c;
	else if (b % 2 == 0) {
		cout<< even(a, b);
	}
	else{
		cout<<odd(a, b);
	}

}