#include <iostream>
#include <vector>

using namespace std;

int n, m = 0;
int result = 0;
vector<vector<int>> rel;
vector<bool> visit;
vector<int> visit_node;

void dfs(int root, int cnt)
{
	// 탈출조건
	if (cnt == 4)
	{
		result = 1;
		return;
	}
	// 순회
	for (int i = 0; i < rel[root].size(); i++)
	{
		if (visit[rel[root][i]] == false)
		{
			visit[rel[root][i]] = true;
			dfs(rel[root][i], cnt + 1);
			visit[rel[root][i]] = false;
		}
	}
}

int main()
{
	// 입력
	cin >> n >> m;
	rel = vector<vector<int>>(n + 1);
	visit = vector<bool>(n + 1, 0);
	while (m--)
	{
		int first = 0;
		int second = 0;
		cin >> first >> second;
		rel[first].push_back(second);
		rel[second].push_back(first);
	}
	for (int i = 0; i < n; i++)
	{
		visit[i] = true;
		dfs(i, 0);
		visit[i] = false;
		if (result == 1)
			break;
	}
	cout << result;
}