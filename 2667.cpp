#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> map;
vector<vector<int>> map_assign;
vector<vector<bool>> visit;
int num = 1;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int range, int x, int y)
{
	visit[x][y] = true;
	map_assign[x][y] = num;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		// 범위 체크
		if (next_x < 0 || next_x >= range)
			continue;
		if (next_y < 0 || next_y >= range)
			continue;
		// 방문 체크
		if (visit[next_x][next_y] == true)	
			continue;
		if (map[next_x][next_y] == 0)
			continue;
		dfs(range, next_x, next_y);
	}
	return;
}

int main()
{
	int n = 0;
	cin >> n;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	map_assign = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	visit = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

	// 입력
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				dfs(n, i, j);
				num++;
			}
		}
	}

	vector<int> num_count(n * n + 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int number = map_assign[i][j];
			if (number == 0)
				continue;
			else
			{
				num_count[number]++;
			}
		}
	}
	cout << num - 1 << '\n';
	sort(num_count.begin(), num_count.end());
	for (int i = 1; i < num_count.size(); i++)
	{
		if (num_count[i] == 0)
			continue;
		cout << num_count[i] << '\n';
	}
}