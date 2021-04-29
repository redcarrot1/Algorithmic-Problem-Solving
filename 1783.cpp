#include <iostream>
using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	int N, M;
	scanf("%d %d",&N, &M);
	if (N == 1) printf("1");
	else if (N == 2) printf("%d", min(4, (M + 1) / 2));
	else if (M < 7) printf("%d", min(4, M));
	else printf("%d", M - 7 + 5);
}
