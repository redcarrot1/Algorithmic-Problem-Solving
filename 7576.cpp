#include <iostream>
#include <vector>
using namespace std;

int x, y;
vector< vector<int> > arr;
vector<pair<int, int>> renode;


void print() {
    for (int i = 0; i < y; i++) {
        for (int k = 0; k < x; k++) {
            printf("%d ", arr[i][k]);
        }
        printf("\n");
    }
}

void extend(int i, int k, int count) {

    if (i - 1 >= 0) {
        if (arr[i - 1][k] == 0) {
            arr[i - 1][k] = count;
            renode.push_back(make_pair(i - 1, k));
        }
    }
    if (i + 1 < y) {
        if (arr[i + 1][k] == 0) {
            arr[i + 1][k] = count;
            renode.push_back(make_pair(i + 1, k));
        }
    }
    if (k - 1 >= 0) {
        if (arr[i][k - 1] == 0) {
            arr[i][k - 1] = count;
            renode.push_back(make_pair(i, k - 1));
        }
    }
    if (k + 1 < x) {
        if (arr[i][k + 1] == 0) {
            arr[i][k + 1] = count;
            renode.push_back(make_pair(i, k + 1));
        }
    }
}


int check() { //아직이면 0, 끝나면 1
    for (int i = 0; i < y; i++) {
        for (int k = 0; k < x; k++) {
            if (arr[i][k] == 0) return 0;
        }
    }
    return 1;
}

int preextend(int count) {
    if (check() == 1) return count;

    int size = renode.size();
    for (int i = 0; i < size; i++) {
        extend(renode[i].first, renode[i].second, count + 2);
    }
    renode.erase(renode.begin(), renode.begin()+size);
    count++;

    if (count == x * y) return -1;
    printf("\n======%d일차======\n", count);
    print();
    return preextend(count);
}


void dataInsert() {
    scanf("%d %d", &x, &y);
    for (int i = 0; i < y; i++) {
        vector<int> element(x);
        arr.push_back(element);
    }
    int n;
    for (int i = 0; i < y; i++) {
        for (int k = 0; k < x; k++) {
            scanf("%d", &n);
            arr[i][k] = n;
        }
    }
}

int main() {
    dataInsert();
    for (int i = 0; i < y; i++) {
        for (int k = 0; k < x; k++) {
            if (arr[i][k] == 1) renode.push_back(make_pair(i, k));
        }
    }
    int count = 0;
    printf("%d", preextend(count));
}