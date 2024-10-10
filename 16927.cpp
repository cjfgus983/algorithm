#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector < vector<int >> arr;

void Rotate(int k) // k�� ��� ������
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

int main()
{
	cin >> n >> m >> r;
	arr = vector<vector<int>>(n, vector<int>(m, 0));
	vector<int> k_cnt;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	int maxL = max(n, m);
	int minL = min(n, m);
	
	// ��� �ݺ������� ����� ������ �˾ƾ� ��

	// 1. ���� �� �� ������
	int k = minL / 2;
	// �� ���� ��� �ݺ�����
	for (int i = 0; i < k; i++)
	{
		int rotate_cnt = (maxL - 2 * i) * 2 + (minL - 2 * (i +1 )) * 2; // �ѹ��� ȸ�� Ƚ��
		
		int cnt = r % rotate_cnt; // k ���������� cnt��ŭ�� ���� ��
		while (cnt--)
		{
			Rotate(i);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
}