#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;
int n;
int main() {
	int n;
	int arr[8] = { 0, };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	sort(arr+1, arr + n+1);

	do {
		for (int i = 1; i <= n; i++) {
			printf("%d ", arr[i]);
		}
		cout << '\n';
	} while (next_permutation(arr+1, arr +1+ n));
}