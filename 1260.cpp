#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, v;
vector<vector<int>> rel;
vector<bool> visit;

vector<int> v_dfs;
vector<int> v_bfs;

void dfs(int start, int cnt)
{
	visit[start] = true;
	v_dfs.push_back(start);
	if (cnt == n)
	{
		return;
	}
	for (int i = 0; i < rel[start].size(); i++)
	{
		int nextNode = rel[start][i];
		if (visit[nextNode] == true)
			continue;
		dfs(nextNode, cnt + 1);
	}
}

void bfs(int start)
{
	fill(visit.begin(), visit.end(), false);
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int node1 = q.front();
		v_bfs.push_back(node1);
		q.pop();
		for (int i = 0; i < rel[node1].size(); i++)
		{
			int node2 = rel[node1][i];
			if (visit[node2] == true)
				continue;
			q.push(node2);
			visit[node2] = true;
		}
	}
	for (int i = 0; i < v_bfs.size(); i++)
	{
		cout << v_bfs[i] << ' ';
	}
}

int main()
{
	cin >> n >> m >> v;
	rel = vector<vector<int>>(n + 1);
	visit = vector<bool>(n + 1, 0);
	while(m--)
	{
		int point1, point2;
		cin >> point1 >> point2;
		rel[point1].push_back(point2);
		rel[point2].push_back(point1);
	}
	for (int i = 0; i <= n; i++)
	{
		sort(rel[i].begin(), rel[i].end());
	}
	dfs(v, 1);
	for (int i = 0; i < v_dfs.size(); i++)
	{
		cout << v_dfs[i] << ' ';
	}
	cout << '\n';
	bfs(v);
}