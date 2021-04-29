#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

//소수=true 합성수=false
int check[10001];

bool prime[10001];
void eratos() {
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		prime[i] = !prime[i];
	}
}

int che(int num, int index, int digit) {
	if (index == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[index] = digit + '0';
	return stoi(s);
}

int main() {
	int t;
	cin >> t;
	eratos();
	while (t--) {
		int start, goal;
		cin >> start >> goal;
		memset(check, 0, sizeof(check));
		queue<int> q;

		check[start] = 1;
		q.push(start);

		while (!q.empty()) {
			int num = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				for (int k = 0; k <= 9; k++) {
					int temp = che(num, i, k);
					if (temp != -1) {
						if (prime[temp] == true && check[temp] == 0) {
							q.push(temp);
							check[temp] = check[num] + 1;
						}
					}
				}
			}
		}
		cout << check[goal] - 1 << '\n';
	}
}