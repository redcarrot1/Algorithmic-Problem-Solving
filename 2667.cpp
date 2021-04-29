#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>v;
int Size;
int dangi[25 * 25] = { 0, };
int check[25 * 25] = { 0, };


void dataInsert() {
    char c;
    scanf("%d", &Size);
    for (int i = 0; i < Size; i++) {
        vector<int> element(Size);
        v.push_back(element);
    }

    scanf("%c", &c); //엔터먹는용
    for (int i = 0; i < Size; i++) {
        for (int k = 0; k < Size; k++) {
            scanf("%c", &c);
            v[i][k] = c - '0';
        }
        scanf("%c", &c); //엔터먹는용
    }
}


void checking(int i, int k, int count) {
    dangi[count]++;
    check[i*Size+k] = 1;

    //v[i][k]=count 그 주변을 살펴보자
    if (i - 1 >= 0) {
        if (v[i - 1][k] == 1 && check[(i-1) * Size + k] != 1) {
            checking(i - 1, k, count);
        }
    }
    if (i + 1 < Size) {
        if (v[i + 1][k] == 1 && check[(i+1) * Size + k] != 1) {
            checking(i + 1, k, count);
        }
    }
    if (k - 1 >= 0) {
        if (v[i][k-1] == 1 && check[i * Size + k-1] != 1) {
            checking(i, k - 1, count);
        }
    }
    if (k + 1 < Size) {
        if (v[i][k + 1] == 1 && check[i * Size + k+1] != 1) {
            checking(i, k + 1, count);
        }
    }
}


int dfs() {
    int count = 0;
    for (int i = 0; i < Size; i++) {
        for (int k = 0; k < Size; k++) {
            if (v[i][k] == 1 && check[i * Size + k]==0) {
                checking(i, k, count);
                count++;
            }
        }
    }
    return count;
}

int main() {
    dataInsert();
    int count=dfs();
    
    sort(dangi, dangi + count);
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d\n", dangi[i]);
    }
}