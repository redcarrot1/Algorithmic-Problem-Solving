#include <iostream>
using namespace std;

void insertData(int a[1000][8], int t) {
	for (int i = 0; i < t; i++) {
		for (int k = 0; k < 8; k++) {
			scanf("%1d", &a[i][k]);
		}
	}
}
int main() {
	int a[4][8];
	int t, k;
	scanf("%d", &t);
	insertData(a, t);
	scanf("%d", &k);
	

	int w, d;
	while (k--) {
		scanf("%d %d", &w, &d);
		w -= 1;
		int temp1 = w, temp2 = w;

		for (int i = w; i >= 1; i--) {
			if (i == 1) {
				if (a[1][6] == a[0][2]) {
					temp1 = 1;
				}
				else temp1 = 0;
				break;
			}

			if (a[i][6] == a[i - 1][2]) {
				temp1 = i;
				break;
			}
		}
		for (int i = w; i < t - 1; i++) {
			if (i == t-2) {
				if (a[t-1][6] == a[t-2][2]) {
					temp2 = t-2;
				}
				else temp2 = t-1;
				break;
			}

			if (a[i][2] == a[i + 1][6]) {
				temp2 = i;
				break;
			}
		}

		if ((w - temp1) % 2 == 1) d *= -1;

		for (int i = temp1; i <= temp2; i++) {
			//printf("%d번째 톱니 움직임!\n", i);
			if (d == -1) {
				int o = a[i][0];
				for (int j = 0; j < 7; j++) {
					a[i][j] = a[i][j + 1];
				}
				a[i][7] = o;
			}
			else {
				int o = a[i][7];
				for (int j = 7; j >=1; j--) {
					a[i][j] = a[i][j-1];
				}
				a[i][0] = o;
			}
			d *= -1;
		}



		/*printf("\n============\n");
		for (int i = 0; i < t; i++) {
			for (int k = 0; k < 8; k++) {
				printf("%d ", a[i][k]);
			}
			printf("\n");
		}*/
	}

	int ans = 0;
	for (int i = 0; i < t; i++) {
		if (a[i][0] == 1) {
			ans += 1;
		}
	}
	cout << ans << '\n';
}