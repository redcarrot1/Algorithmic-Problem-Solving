#include <stdio.h>
#include <vector>
using namespace std;
//참고
//https://m.blog.naver.com/PostView.nhn?blogId=icbanq&logNo=221727893563&proxyReferer=https:%2F%2Fwww.google.com%2F
vector<int> v;

int main() {
	char n;
	while (1) {
		scanf("%1c", &n);
		n = n - '0';
		if (n < 0 || n>1) break;
		v.push_back(n);
	}

	//패딩 2개
	if (v.size() % 3 == 1) v.insert(v.begin(), 2, 0);
	//패딩1개
	else if (v.size() % 3 == 2) v.insert(v.begin(), 1, 0);

	for(int i=0; i<v.size(); i=i+3){
		int n = 4 * v[i] + 2 * v[i + 1] + v[i + 2];
		printf("%d", n);
	}
}