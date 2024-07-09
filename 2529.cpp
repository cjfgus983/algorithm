#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int k;
char arr[10];
string max_result = "0";
string min_result = "999999999";
bool visit[10];

void dfs(int cnt, string str)
{
	if (cnt == k)
	{
		max_result = max(max_result, str);
		min_result = min(min_result, str);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (visit[i])
			continue; // 방문했으면 스킵

		if (arr[cnt] == '<' && str[cnt] - '0' < i)
		{
			visit[i] = true;
			dfs(cnt + 1, str + to_string(i));
			visit[i] = false;
		}
		else if(arr[cnt] == '>' && str[cnt]-'0' > i)
		{
			visit[i] = true;
			dfs(cnt + 1, str + to_string(i));
			visit[i] = false;
		}
	}
}


int main()
{
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <= 9; i++)
	{
		visit[i] = true;
		dfs(0, to_string(i));
		visit[i] = false;
	}
	cout << max_result << '\n' << min_result;
}