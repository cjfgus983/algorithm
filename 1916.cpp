#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
int start_node, end_node;
vector<vector<pair<int, int>>> rel(1001);
vector<long long> weight(1001, INT_MAX);

void dijkstra()
{
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // <cost, to> 
	pq.push({ 0,start_node });
	weight[start_node] = 0;
	
	while (!pq.empty())
	{
		int now_cost = pq.top().first;
		int now_node = pq.top().second;
		pq.pop();

		// ¿Ö ÇÊ¿ä?
		/*if (now_cost > weight[now_node])
			continue;*/

		for (int i = 0; i < rel[now_node].size(); i++)
		{
			int next_node = rel[now_node][i].first;
			int next_cost = rel[now_node][i].second;

			if (weight[next_node] > weight[now_node] + next_cost)
			{
				weight[next_node] = weight[now_node] + next_cost;
				pq.push({ weight[next_node], next_node });
			}
		}
	}

}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		rel[from].push_back({ to,cost });
	}
	cin >> start_node >> end_node;
	dijkstra();
	cout << weight[end_node];
}