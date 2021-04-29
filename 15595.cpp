#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
//1h 30m 실패

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);
    int n;
    cin >> n;
    int num, result, me, t, l, len;
    string str;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> num >> str >> result >> me >> t >> l >> len;
        if (str != "megalusion") {
            if (m.find(str) != m.end()) { //이미 m에 있는거라면
                if (m[str] < 0) { //int가 음수라면 ->이미 한번이라도 정답을 맞추면 영향없음
                    if (result == 4) { //정답이면
                        m[str] *= -1; //양수로 바꿔주기
                    }
                    else {
                        m[str]--; //정답이 아니면 --해주기
                    }
                }
            }
            else {  //m에 없는 문자라면
                if (result == 4) {//정답이라면
                    m[str] = 0; //int=0
                }
                else { //오답이라면
                    m[str] = -1; //int=-1
                }
            }

        }
    }
    int cnt = 0;
    int totalMiss = 0;
    for (auto x : m) {
        if (x.second >= 0) {
            cnt++;
        }
        if (x.second > 0) {
            totalMiss += x.second;
        }
    }
    if (cnt == 0) {
        cout << 0;
    }
    else {
        double avg = (double)cnt / (double)(cnt + totalMiss) * 100.0;
        cout << avg;
    }
    return 0;
}