#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
vector<int>v;

void comb(int r) {
    vector<bool> temp(v.size());
    for (int i = 0; i < r; i++)
        temp[i] = true;

    do {
        int sum = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (temp[i]) {
                printf("%d ", v[i]);
            }
        }
        printf("\n");
    } while (prev_permutation(temp.begin(), temp.end()));

    printf("\n");
    temp.clear();
}

int main() {

    while (1) {
        scanf("%d", &k);
        if (k == 0) break;

        int n;
        for (int i = 0; i < k; i++) {
            scanf("%d", &n);
            v.push_back(n);
        }

        sort(v.begin(), v.begin() + v.size());

        comb(6);
        v.clear();
    }
}