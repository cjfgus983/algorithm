#include <iostream>
#include <vector>

using namespace std;

vector<bool> visit(20001,false);
vector<bool> red(20001,false);
vector<bool> blue(20001,false);
bool isConnect = true;
vector<vector<int>> rel;
bool result = true;

void dfs(int start)
{
	if (red[start] == false && blue[start] == false)
	{
		visit[start] = true;
		red[start] = true;
	}

	for (int i = 0; i < rel[start].size(); i++)
	{
		int next_node = rel[start][i];
		if (visit[next_node] == true)
			continue;
		visit[next_node] = true;
		if (red[start] == true && blue[start] == false)
		{
			blue[next_node] = true;
		}
		else if (red[start] == false && blue[start] == true)
		{
			red[next_node] = true;
		}
		dfs(next_node);
	}
}

void check(int v_cnt)
{
	for (int i = 1; i <= v_cnt; i++)
	{
		for (int j = 0; j < rel[i].size(); j++)
		{
			int next_node = rel[i][j];
			if (red[next_node] == red[i] || blue[next_node] == blue[i])
			{
				result = false;
				return;
			}
		}
	}
}

void reset()
{
	fill(visit.begin(), visit.end(), false);
	fill(red.begin(), red.end(), false);
	fill(blue.begin(), blue.end(), false);
	result = true;
}

int main()
{
	int k;
	cin >> k;
	while (k--)
	{
		// ют╥б
		int v, e;
		cin >> v >> e;
		rel = vector<vector<int>>(v + 1, vector<int>(0, 0));
		while (e--)
		{
			int first, second;
			cin >> first >> second;
			rel[first].push_back(second);
			rel[second].push_back(first);
		}
		for (int i = 1; i <= v; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				dfs(i);
			}
		}
		check(v);
		if (result)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
		reset();
	}

}