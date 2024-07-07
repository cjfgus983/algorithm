#include <iostream>

using namespace std;

int map[10][10];
bool visit[10][10];
int n, m, k;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int result = 0;

void dfs(int cnt, int sum) 
{
	if (cnt == k)
	{
		if (result < sum)
		{
			result = sum;
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j] == true)
				continue;
			// 인접한데 방문했는지
			bool skip = false;
			for (int k = 0; k < 4; k++)
			{
				if (i + dx[k] < 0 || i + dx[k] >= 10 || j + dy[k] < 0 || j + dy[k] >= 10)
				{
					continue;
				}

				if (visit[i + dx[k]][j + dy[k]] == true)
				{
					skip = true;
					break;
				}
			}
			if (skip == true)
				continue;

			visit[i][j] = true;
			dfs(cnt+1, sum+map[i][j]);
			visit[i][j] = false;
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	
	dfs(0, 0);
	cout << result;
}