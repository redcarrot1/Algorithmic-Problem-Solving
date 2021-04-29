#include <iostream>
using namespace std;

int main() {
	int n, five = 0;
	scanf("%d", &n);
	if (n == 4 || n == 7) {
		printf("-1");
		return 0;
	}

	int arr[5000][2]{ {0, 0}, };
	arr[3][0] = 1;
	arr[3][1] = 0;

	arr[4][0] = 0;
	arr[4][1] = 0;

	arr[5][0] = 0;
	arr[5][1] = 1;

	arr[6][0] = 2;
	arr[6][1] = 0;

	arr[7][0] = 0;
	arr[7][1] = 0;

	arr[9][0] = 3;
	arr[9][1] = 0;

	arr[12][0] = 4;
	arr[12][1] = 0;


	for (int i = 3; i < n - 4; i++) {
		if (i == 4 || i == 7) continue;

		arr[i + 5][0] = arr[i][0];
		arr[i + 5][1] = arr[i][1] + 1;

	}
	printf("%d", arr[n][0] + arr[n][1]);


}