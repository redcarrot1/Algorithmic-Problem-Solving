#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int a[101];
long long d[101][21]; //d[i][j]= i까지 수를 사용해서 j를 만드는 방법 수
int n, goal;


long long go(int i, int j) {
    if (i < 0) return 0;
	if (d[i][j] != -1) return d[i][j];

    d[i][j] = 0;
    if (j - a[i] >= 0) {
        d[i][j] += go(i - 1, j - a[i]);
    }
    if (j + a[i] <= 20) {
        d[i][j] += go(i - 1, j + a[i]);
    }
    return d[i][j];
}

int main() {
    memset(d, -1, sizeof(d));
    int n;
    cin >> n;
    n -= 1;
  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int goal;
    cin >> goal;
    d[0][a[0]] = 1;
    
    cout << go(n-1, goal) << '\n';
    return 0;
}