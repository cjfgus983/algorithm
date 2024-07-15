#include <iostream>
#include <algorithm>

using namespace std;

int n; // �� ����
int m; // �� ����
int arr[4][4];
bool isRow[4][4]; // �ش� Ÿ���� ���η� ���
int result = 0;

void dfs(int r, int c)
{
	if (r == n) // r�� n�� �ƴٴ� ���� ������ �� ���Ҵٴ� ��.
	{
		int total = 0;
		// ���� ���
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
			{
				if (isRow[i][j] == true) // ����ó�����
				{
					sum = sum * 10 + arr[i][j];
				}
				else // ����ó�����
				{
					total = total + sum;
					sum = 0;
				}
			}
			total = total + sum;
		}
		// ���� ���
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (isRow[i][j] == false) // ����ó�����
				{
					sum = sum * 10 + arr[i][j];
				}
				else // ����ó�����
				{
					total = total + sum;
					sum = 0;
				}
			}
			total = total + sum;
		}
		result = max(total, result);
		return;
	}
	if (c == m) // ���� �� �������� ���� ������
	{
		dfs(r + 1, 0);
		return;
	}

	//�ش� Ÿ���� �ѹ��� ���η�, �ѹ��� ���η� ���
	isRow[r][c] = true;
	dfs(r, c + 1);
	isRow[r][c] = false;
	dfs(r, c + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	cout << result;
}