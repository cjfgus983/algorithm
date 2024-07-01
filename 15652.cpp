#include <iostream>

using namespace std;

bool visit[8];
int result[8];

void dfs(int start, int n, int m, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++)
	{
		result[cnt] = i;
		dfs(i, n, m, cnt + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	dfs(1, n, m, 0);
}