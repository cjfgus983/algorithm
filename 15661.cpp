#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[21][21];
int result = 9999;
bool visit[21];

//�ο����� ���� �ʾƵ� ��

void dfs(int cnt, int start, int condition)
{
	//Ż�� ����
	if (cnt == condition)
	{
		vector<int> link;
		vector<int> start;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == true)
				link.push_back(i);
			else
				start.push_back(i);
		}
		int link_sum = 0;
		int start_sum = 0;
		for (int i = 0; i < link.size() - 1; i++)
		{
			for (int j = i + 1; j < link.size(); j++)
			{
				link_sum = link_sum + arr[link[i]][link[j]] + arr[link[j]][link[i]];
			}
		}
		for (int i = 0; i < start.size() - 1; i++)
		{
			for (int j = i + 1; j < start.size(); j++)
			{
				start_sum = start_sum + arr[start[i]][start[j]] + arr[start[j]][start[i]];
			}
		}

		result = min(result, abs(link_sum - start_sum));
		return;
	}

	// �� ���ϱ�
	for (int i = start; i <= n; i++)
	{
		if (visit[i] == true)
			continue;
		visit[i] = true;
		dfs(cnt + 1, i + 1, condition);
		visit[i] = false;
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n / 2; i++)
	{
		dfs(0, 1, i);
	}
	cout << result;
}