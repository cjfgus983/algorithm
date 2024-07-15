#include <iostream>
#include <vector>

using namespace std;

int n, s;
int result = 0;
int arr[20];
bool visit[20];
vector<int> v;

void dfs(int cnt, int limit, int start)
{
	if (cnt == limit)
	{
		int sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum = sum + v[i];
		}
		if (sum == s)
		{
			result++;
		}
		return;
	}

	for (int i = start; i < n; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt +1, limit, i+1);
		visit[i] = false;
		v.pop_back();
	}
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(0, i, 0);
	}
	cout << result;
}