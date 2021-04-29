#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;

	int d[100001];
	fill(d, d + 100001, 2147483647);

	priority_queue<pair<int, int> > pq;
	pq.push({ 0, N });
	d[N] = 0;

	while (!pq.empty())
	{
		int now_cost = -pq.top().first;
		int now_idx = pq.top().second;
		pq.pop();

		if (now_idx == K) break;

		if (now_idx <= 50000 && d[2 * now_idx] > now_cost)
		{
			d[2 * now_idx] = now_cost;
			pq.push({ -now_cost, 2 * now_idx });
		}

		if (now_idx > 0 && d[now_idx - 1] > now_cost + 1)
		{
			d[now_idx - 1] = now_cost + 1;
			pq.push({ -(now_cost + 1), now_idx - 1 });
		}

		if (now_idx < 100000 && d[now_idx + 1] > now_cost + 1)
		{
			d[now_idx + 1] = now_cost + 1;
			pq.push({ -(now_cost + 1), now_idx + 1 });
		}
	}

	cout << d[K] << endl;



}