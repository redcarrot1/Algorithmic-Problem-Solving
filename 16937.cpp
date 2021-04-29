#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int h, w, n;
vector<pair<int, int>> v;

bool cu(int h1, int w1, int h2, int w2) {
	//���η� �����ִ� ���
	if (w1 + w2 <= w && max(h1, h2) <= h) return true;

	//���η� �����ִ� ���
	if (h1 + h2 <= h && max(w1, w2) <= w) return true;

	return false;
}

int getArea(int one, int two) {
	//������, one 90��, two 90��, �Ѵ� 90��
	int h1 = v[one].first;
	int w1 = v[one].second;
	int h2 = v[two].first;
	int w2 = v[two].second;
	int ans = h1 * w1 + h2 * w2;

	if (cu(h1, w1, h2, w2)) return ans;
	if (cu(w1, h1, h2, w2)) return ans;
	if (cu(h1, w1, w2, h2)) return ans;
	if (cu(w1, h1, w2, h2)) return ans;

	return 0;
}

int main() {
	cin >> h >> w >> n;
	int x, y;

	for (int i = 0; i < n; i++) {
		cin >> y >> x;
		v.push_back(make_pair(y, x));
	}


	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, getArea(i, j)); /* ���� ���� */
		}
	}

	cout << ans;
}