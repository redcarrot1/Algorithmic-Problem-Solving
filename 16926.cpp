#include <iostream>
using namespace std;
//16926, 16927번 문제
//외각에서 k칸 떨어진 그룹=group_num
int n, m, r, can_group;
int arr[300][300];

void insertData() {
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[i][k];
		}
	}
	if (n < m) can_group = n / 2;
	else can_group = m / 2;
}

void rotation(int group_num) {
	int a[1205];

	int k = 0;
	for (int i = group_num; i < m - 1 - group_num; i++, k++) {
		a[k] = arr[group_num][i];
	}
	for (int i = group_num; i < n - 1 - group_num; i++, k++) {
		a[k] = arr[i][m - 1 - group_num];
	}
	for (int i = m - 1 - group_num; i > group_num; i--, k++) {
		a[k] = arr[n - 1 - group_num][i];
	}
	for (int i = n - 1 - group_num; i > group_num; i--, k++) {
		a[k] = arr[i][group_num];
	}

	/*for (int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
	cout << '\n';*/
	//0~k-1
	int temp;
	for (int i = 0; i < r%(2*(m+n)-4-8*group_num); i++) {
		temp = a[0];
		for (int q = 0; q < k - 1; q++) {
			a[q] = a[q + 1];
		}
		a[k - 1] = temp;
		/*cout << "\n"<<group_num<<"번 그룹 "<<i<<"번 회전\n";
		for (int i = 0; i < k; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";*/
	}

	k = 0;
	for (int i = group_num; i < m - 1 - group_num; i++, k++) {
		arr[group_num][i] = a[k];
	}
	for (int i = group_num; i < n - 1 - group_num; i++, k++) {
		arr[i][m - 1 - group_num] = a[k];
	}
	for (int i = m - 1 - group_num; i > group_num; i--, k++) {
		arr[n - 1 - group_num][i] = a[k];
	}
	for (int i = n - 1 - group_num; i > group_num; i--, k++) {
		arr[i][group_num] = a[k];
	}
	//arr[group_num + 1][group_num] = a[k - 1];
}

void go() {
	for (int i = 0; i < can_group; i++) {
		rotation(i);

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	insertData();
	go();
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
}