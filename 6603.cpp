#include <iostream>
#include <vector>

using namespace std;

int arr[13];
bool visit[13];
vector<int> v;
int n;

void dfs(int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++)
			{
				if (v[i] > v[j])
					return;
			}
		}


		for (int i = 0; i < 6; i++)
		{
			cout << v[i] <<' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}


int main()
{
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		dfs(0);
		cout << '\n';
	}
}