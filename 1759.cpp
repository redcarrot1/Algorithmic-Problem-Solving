#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char>arr;
void comb(int r) {
    vector<bool> temp(arr.size());
    for (int i = 0; i < r; i++)
        temp[i] = true;
    do {
        int w = 0;
        int a = 0;
        string str;
        for (int i = 0; i < arr.size(); ++i) {
            if (temp[i]) {
                if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') a++;
                else w++;
                string s(1, arr[i]);
                str = str + s;
            }
        }
        if (a >= 1 && w >= 2) cout << str << "\n";
    } while (prev_permutation(temp.begin(), temp.end()));
}
int main() {
    int l, c;
    scanf("%d %d", &l, &c);
    char q;
    for (int i = 0; i < c; i++) {
        scanf("%c", &q);
        scanf("%c", &q);
        arr.push_back(q);
    }

    sort(arr.begin(), arr.end());
    comb(l);
}