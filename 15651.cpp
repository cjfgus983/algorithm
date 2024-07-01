#include <iostream>

using namespace std;

bool visit[8];
int result[8];

void dfs(int n, int m, int cnt)
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
	for (int i = 1; i <= n; i++)
	{
		result[cnt] = i;
		dfs(n, m, cnt + 1);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0);
}