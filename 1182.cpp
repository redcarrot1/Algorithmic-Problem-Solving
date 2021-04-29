#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;
int reach, num=0, Size;

void insertData() {
    int n;
    scanf("%d %d", &Size, &reach);
    for (int i = 0; i < Size; i++) {
        scanf("%d", &n);
        arr.push_back(n);
    }
}

void comb(int r) {
    vector<bool> temp(arr.size());
    for (int i = 0; i < r; i++)
        temp[i] = true;

    do {
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (temp[i]) {
                sum += arr[i];
                //printf("%d ", arr[i]);
            }
        }
        if (sum == reach) num++;
        //printf("\n");
    } while (prev_permutation(temp.begin(), temp.end()));
}

int main() {
    insertData();
    for (int i = 1; i <= Size; i++) {
        comb(i);
    }
    printf("%d", num);
}