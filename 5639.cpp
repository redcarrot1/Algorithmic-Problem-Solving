#include <iostream>
using namespace std;

int arr[10001];
//ȣ���ϰ�(��->��) print,  ���� ȣ���Ұ� �ϳ��� ������ �ٷ� print
//���� �ڽź��� ���� ���ڰ� ���ʿ� ���ٸ� ���ʲ��� ȣ���Ұ� ���ٴ� ��
//���� �ڽź��� ū ���ڰ� ���ʿ� ���ٸ� �����ʲ��� ȣ���Ұ� ���ٴ� ��

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

	//left_end==start�� ���ʲ��� ȣ���Ұ� ���ٴ� ��
	if (left_end!=start) go(start + 1, left_end);

	//left_end==end�� �����ʲ��� ȣ���Ұ� ���ٴ� ��
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