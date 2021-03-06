#include<iostream>
using namespace std;

int d[101][100001];
int w[101];
int v[101];

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }


    //D[i][j]=i번째 물건까지 고려했고, 배낭에 넣은 무게가 j일 때, 가치의 최댓값
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++) {
            d[i][j] = d[i - 1][j]; //물건을 넣지 않는 경우, 무게와 가치는 그대로이다.

            //물건을 넣는 경우를 살펴보자
            //현재까지 넣은 배낭의 무게가 이번에 넣을 물건의 무게보다 작으면 넘어간다.
            if (j - w[i] >= 0) {

                //i번째 물건을 넣기 전, 즉 i-1번째 물건까지 고려했고 배낭의 무게가 (j-이번 물건의 무게) = d[i-1][j-w[i]]
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << d[n][k];


    /*
    어차피 d[i][j]는 d[i-1][j]에서 바로 위(d[i-1][j])와 윗줄의 왼쪽(d[i - 1][j - w[i]])만 고려하기 때문에
    1차원 배열로 구현 가능하다.
    단, 앞에서부터 업데이트하면 d[i - 1][j - w[i]]값이 업데이트 되어버리므로, d[i][j]에 잘못된 값이 들어간다.
    즉, 앞에서부터가 아닌, 뒤에서부터 업데이트를 실시하면 해결된다.

      int d[100001];
      for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++) {
            if(j-w[i]>=0) d[j]=max(d[j], d[j-w[i]]+v[i]);
          }
       }
    */
}
