#include <iostream>
#include <algorithm>

using namespace std;

bool visit[8];
int result[8];
int arr[8];

void dfs(int n, int m, int cnt, int start)
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
	for (int i = start; i < n; i++)
	{
		if (visit[i] == false)
		{
			result[cnt] = arr[i];
			visit[i] = true;
			dfs(n, m, cnt + 1,i+1);
			visit[i] = false;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	dfs(n, m, 0, 0);
}