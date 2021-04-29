#include <iostream>
using namespace std;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int a[55][55];
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    // a[x][y] == 0 (청소하지 않은 공간)
    // a[x][y] == 1 (벽)
    // a[x][y] == 2 (청소한 공간)
    while (true) {
        if (a[x][y] == 0) {
            // 1. 현재 위치를 청소한다.
            a[x][y] = 2;
        }
        // 2-3, 2-4. 네 방향 모두 청소가 이미 되어있거나 벽인 경우
        if (a[x + 1][y] != 0 && a[x - 1][y] != 0 && a[x][y - 1] != 0 && a[x][y + 1] != 0) {
            if (a[x - dx[dir]][y - dy[dir]] == 1) {
                // 2-4. 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
                break;
            }
            else {
                // 2-3. 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
                x -= dx[dir];
                y -= dy[dir];
            }
        }
        else {
            // 2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음
            // 2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.

            dir = (dir + 3) % 4;
            if (a[x + dx[dir]][y + dy[dir]] == 0) {
                // 2-1. 한 칸을 전진하고 1번부터 진행한다.
                x += dx[dir];
                y += dy[dir];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 2) {
                cnt += 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}