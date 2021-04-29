#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char leftt[16] = { 'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v', 'b', 'y' };

string str;


int check(char c) {
	for (int i = 0; i < 16; i++) {
		if (leftt[i] == c) return 1;
	}
	return -1;
}

int main() {
	int ee = 0;
	int lcount = 0, rcount = 0;
	getline(cin, str, '\n');
	char temp;
	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			temp = tolower(str[i]);
			ee += 1;
		}
		else if (str[i] == ' ') {
			ee += 1;
			continue;
		}
		else temp = str[i];

		if (check(temp) == 1) lcount += 1;
		else rcount += 1;
	}

	for (int i = 0; i < ee; i++) {
		if (rcount >= lcount) {
			lcount += 1;
		}

		else {
			rcount += 1;
		}
	}
	cout << lcount << " " << rcount;
}