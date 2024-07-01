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
	}
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			result[cnt] = i;
			visit[i] = true;
			dfs(n, m, cnt + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	dfs(n, m, 0);

}