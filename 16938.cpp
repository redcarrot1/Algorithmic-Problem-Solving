#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한
//가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다.
//두문제 이상

long long n, l, r, x;
vector<long long> v;
long long ans = 0;
void comb(int q) {
    vector<bool> temp(n);
    for (int i = 0; i < q; i++)
        temp[i] = true;

    do {
        long long sum = 0;
        long long di=0, ea=1000001;
        for (int i = 0; i < n; ++i) {
            if (temp[i]) {
                sum += v[i];
                if (v[i] > di) di = v[i];
                if (v[i] < ea) ea = v[i];
                if (sum > r) break;
            }
        }
        
        if (sum >= l && sum <= r && (di - ea) >= x) ans += 1;

    } while (prev_permutation(temp.begin(), temp.end()));
}

int main() {
	cin >> n >> l >> r >> x;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}

    for (int i = 2; i <= n; i++) {
        comb(i);
    }
    cout << ans;

}