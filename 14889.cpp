#include <iostream>
#include <vector>
using namespace std;

int s[20][20];
int n;
int diff = 1000000000;
vector<int> start;
vector<int> link;


int sumstart() {
	int k = 0;
	for (int i = 0; i < n/2; i++) {
		for (int q = 0; q < n / 2; q++) {
			int person1 = start[i];
			int person2 = start[q];
			k += s[person1][person2];
		}
	}
	return k;
}

int linkstart() {
	int k = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int q = 0; q < n / 2; q++) {
			int person1 = link[i];
			int person2 = link[q];
			k += s[person1][person2];
		}
	}
	return k;
}

void go(int start_num, int link_num, int index) {
	if (start_num > n / 2) return;
	if (link_num > n / 2) return;
	
	if (index == n) {
		int start_sum = sumstart();
		int link_sum = linkstart();
		int tdiff = start_sum - link_sum;

		if (tdiff < 0) tdiff = -tdiff;
		if (diff > tdiff) diff = tdiff;
		return;
	}


	start.push_back(index);
	go(start_num + 1, link_num, index + 1);
	start.pop_back();

	link.push_back(index);
	go(start_num, link_num+1, index + 1);
	link.pop_back();
	
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> s[i][k];
		}
	}

	go(0, 0, 0);
	cout << diff;
}