#include <iostream>
using namespace std;


int a[13];
bool use[13];
int k;
void go(int cnt, int i) {
	if (i ==k) {
		if (cnt == 6) {
			for (int q = 0; q < k; q++) {
				if (use[q]) cout << a[q]<<" ";
			}
			cout << '\n';
		}
		return;
	}

	//i번째 수를 사용하는 경우 -> use[i]=true, cnt+1, i+1
	use[i] = true;
	go(cnt + 1, i + 1);

	use[i] = false;
	go(cnt, i + 1);

}

int main() {
	while (1) {
		cin >> k;
		if (k == 0) return 0;

		for (int i = 0; i < k; i++) {
			cin >> a[i];
		}
		go(0, 0);
		cout << "\n";
	}

}