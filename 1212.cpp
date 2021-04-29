#include <stdio.h>
#include <vector>
using namespace std;
//Âü°í
//https://m.blog.naver.com/PostView.nhn?blogId=icbanq&logNo=221727893563&proxyReferer=https:%2F%2Fwww.google.com%2F
vector<int> v;

void convert(int i) {
	if (i == 0) printf("000");
	if (i == 1) printf("001");
	if (i == 2) printf("010");
	if (i == 3) printf("011");
	if (i == 4) printf("100");
	if (i == 5) printf("101");
	if (i == 6) printf("110");
	if (i == 7) printf("111");
}

int main() {
	char n;
	while (1) {
		scanf("%1c", &n);
		n = n - '0';
		if (n < 0 || n>7) break;
		v.push_back(n);
	}
	if (v[0] == 0 && v.size() == 1) {
		printf("0");
		return 0;
	}
	if (v[0] == 1) printf("1");
	if (v[0] == 2) printf("10");
	if (v[0] == 3) printf("11");
	if (v[0] == 4) printf("100");
	if (v[0] == 5) printf("101");
	if (v[0] == 6) printf("110");
	if (v[0] == 7) printf("111");

	for (int i = 1; i < v.size(); i++) {
		convert(v[i]);
	}
}