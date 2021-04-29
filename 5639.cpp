#include <iostream>
using namespace std;

int arr[10001];
//호출하고(왼->오) print,  만약 호출할게 하나도 없으면 바로 print
//만약 자신보다 작은 숫자가 왼쪽에 없다면 왼쪽꺼는 호출할게 없다는 뜻
//만약 자신보다 큰 숫자가 왼쪽에 없다면 오른쪽꺼는 호출할게 없다는 뜻

void go(int start, int end) {
	if (start == end) {
		cout << arr[start] << "\n";
		return;
	}
	int root = arr[start];
	

	int left_end = start;
	for (int i = start + 1; i <= end; i++)  {
		if (root > arr[i]) left_end = i; 
	}

	//left_end==start면 왼쪽꺼는 호출할게 없다는 뜻
	if (left_end!=start) go(start + 1, left_end);

	//left_end==end면 오른쪽꺼는 호출할게 없다는 뜻
	if (left_end!=end) go(left_end + 1, end);

	cout << root << '\n';
}

int main() {
	int a;
	int i = 0;
	char c;
	while (cin >> a) {
		arr[i] = a;
		i += 1;
	}
	go(0, i-1);
}