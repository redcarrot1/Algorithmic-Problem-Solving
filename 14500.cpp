#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[500][500];
int N, M;
int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,0}, {2,0}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {0,2}, {-1,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{0,1}, {0,2}, {-1,1}},
    {{0,1}, {0,2}, {1,1}},
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}},
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            cin >> a[i][k];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 19; k++) {
                bool ok = true;
                int sum = a[i][j];
                for (int l = 0; l < 3; l++) {
                    int x = i + block[k][l][0];
                    int y = j + block[k][l][1];
                    if (0 <= x && x < N && 0 <= y && y < M) {
                        sum += a[x][y];
                    }
                    else {
                        ok = false; //4개 칸 중 한개라도 else로 들어가면 false
                        break;
                    }
                }
                if (ok && ans < sum) {
                    ans = sum;
                }
            }
        }
    }
    cout << ans << '\n';
}