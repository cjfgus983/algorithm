#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[10][10];
bool visit[10];
int result = 10000001;

void dfs(int cnt, int prev, int sum)
{
	if (cnt == n-1)
	{
		if (arr[prev][0] == 0) // �������� 0���� ���� ����� ������
			return;
		sum = sum + arr[prev][0];
		result = min(result, sum);
		return;
	}
	for (int i = 1; i < n; i++)
	{
		if (visit[i] || arr[prev][i] == 0) // �������ø� �湮�߰ų� ����� ������
			continue;
		visit[i] = true;
		dfs(cnt + 1, i, sum + arr[prev][i]);
		visit[i] = false;
	}
}

int main()
{
	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	dfs(0, 0, 0);
	cout << result;
}