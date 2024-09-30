#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

vector < vector<pair<int, int>>> rel(801);
vector<long long> weight(801, INT_MAX);

int dijkstra(int start_node, int end_node)
{
	fill(weight.begin(), weight.end(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	weight[start_node] = 0;
	pq.push({ weight[start_node], start_node });

	while (!pq.empty())
	{
		int now_node = pq.top().second;
		int now_weight = pq.top().first;
		pq.pop();

		if (weight[now_node] < now_weight)
			continue;
		for (int i = 0; i < rel[now_node].size(); i++)
		{
			int next_node = rel[now_node][i].first;
			int next_weight = rel[now_node][i].second;
			if (weight[next_node] > weight[now_node] + next_weight)
			{
				weight[next_node] = weight[now_node] + next_weight;
				pq.push({ weight[next_node], next_node });
			}
		}
	}
	return weight[end_node];
}

int main()
{
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		rel[a].push_back({ b,c});
		rel[b].push_back({ a,c });
	}

	int point1, point2;
	cin >> point1 >> point2;

	int d1 = dijkstra(1, point1);
	int d2 = dijkstra(point1, point2); 
	int d3 = dijkstra(point2, n);

	int d4 = dijkstra(1, point2);
	int d5 = dijkstra(point2, point1);
	int d6 = dijkstra(point1, n);

	if (d1 == INT_MAX || d2 == INT_MAX || d3 == INT_MAX)
		cout << -1 << '\n';
	else
	{
		cout << min(d1 + d2 + d3, d4 + d5 + d6);
	}
}