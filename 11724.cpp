#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;
int result = 0;
bool visit[1001];
vector<vector<int>> rel;

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int next_node = q.front();
		q.pop();
		for (int i = 0; i < rel[next_node].size(); i++)
		{
			if (visit[rel[next_node][i]])
				continue;
			q.push(rel[next_node][i]);
			visit[rel[next_node][i]] = true;
		}
	}
}

int main()
{
	cin >> n >> m;
	rel = vector<vector<int>>(n + 1);
	while (m--)
	{
		int node1, node2;
		cin >> node1 >> node2;
		rel[node1].push_back(node2);
		rel[node2].push_back(node1);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == true)
			continue;
		result++;
		bfs(i);
	}
	cout << result;
}