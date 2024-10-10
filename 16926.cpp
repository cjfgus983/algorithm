#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector < vector<int >> arr;

void Rotate(int block)
{
	for (int k = 0; k < block; k++) // ��㸶�� ȸ�� ����
	{
		int tmp = arr[k][k];
		// ����
		for (int i = k; i <= m - 2 - k; i++)
		{
			arr[k][i] = arr[k][i + 1];
		}
		// ������
		for (int i = k; i <= n - 2 - k; i++)
		{
			arr[i][m - 1 - k] = arr[i + 1][m - 1 - k];
		}
		// �Ʒ���
		for (int i = m - 1 - k; i >= 1 + k; i--)
		{
			arr[n - k - 1][i] = arr[n - k - 1][i - 1];
		}
		// ����
		for (int i = n - 1 - k; i >= 1 + k; i--)
		{
			arr[i][k] = arr[i - 1][k];
		}

		arr[k + 1][k] = tmp;
	}
}

int main()
{
	cin >> n >> m >> r;
	arr = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int block = min(n, m) / 2; // ��
	while (r--)
	{
		Rotate(block);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << '\n';
	}
}