#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m; // 도시 , 버스
vector<vector<long long >> dist(101, vector<long long>(101, INT_MAX));

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		long long from, to, cost;
		cin >> from >> to >> cost;
		dist[from][to] = min(dist[from][to], cost);
	}
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}

	// 플로이드
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] >= INT_MAX)
			{
				cout << 0 << ' ';
				continue;
			}
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

}