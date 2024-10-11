#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l;
vector<vector<int>> arr;
int result;

int main()
{
	cin >> n >> l;
	arr = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int result = 0;
	// ���� ���� ����
	for (int i = 0; i < n; i++)
	{
		bool check = true;
		vector<int> visit(n, 0);
		for (int j = 0; j < n - 1; j++)
		{
			int now = arr[i][j];
			int next = arr[i][j + 1];
			if (now == next) // �� ������ pass
				continue;
			// case 1 2�� ���̰� ������ �Ұ�
			if (abs(next - now) >= 2)
			{
				check = false;
				break;
			}
			// case 2 next�� �� Ŭ ��� now���� �Ʒ��� L������ŭ �Ǵ���
			if (now < next)
			{
				for (int k = j; k > j - l; k--)
				{
					if (k < 0) // ���� �ʰ� ��
					{
						check = false;
						break;
					}
					if (now != arr[i][k])
					{
						check = false;
						break;
					}
					if (check == false)
						break;
					visit[k]++;
				}
			}
			// case 3 next�� �� ���� ���
			if (now > next)
			{
				for (int k = j + 1; k < j + 1 + l; k++)
				{
					if (k >= n) // ���� �ʰ� �� 
					{
						check = false;
						break;
					}
					if (next != arr[i][k])
					{
						check = false;
						break;
					}
					if (check == false)
						break;
					visit[k]++;
				}
			}
			// case 4 �ߺ��ؼ� ��縦 �� ���
			for (int i = 0; i < n; i++)
			{
				if (visit[i] > 1)
				{
					check = false;
					break;
				}
			}
		}
		if (check == true)
		{
			result++;
			/*cout << i << "��\n";*/
		}
	}

	// ��
	for (int i = 0; i < n; i++)
	{
		bool check = true;
		vector<int> visit(n, 0);
		for (int j = 0; j < n - 1; j++)
		{
			int now = arr[j][i];
			int next = arr[j + 1][i];
			if (now == next) // �� ������ pass
				continue;
			// case 1 2�� ���̰� ������ �Ұ�
			if (abs(next - now) >= 2)
			{
				check = false;
				break;
			}
			// case 2 next�� �� Ŭ ��� now���� �Ʒ��� L������ŭ �Ǵ���
			if (now < next)
			{
				for (int k = j; k > j - l; k--)
				{
					if (k < 0) // ���� �ʰ� ��
					{
						check = false;
						break;
					}
					if (now != arr[k][i])
					{
						check = false;
						break;
					}
					if (check == false)
						break;
					visit[k]++;
				}
			}
			// case 3 next�� �� ���� ���
			if (now > next)
			{
				for (int k = j + 1; k < j + 1 + l; k++)
				{
					if (k >= n) // ���� �ʰ� �� 
					{
						check = false;
						break;
					}
					if (next != arr[k][i])
					{
						check = false;
						break;
					}
					if (check == false)
						break;
					visit[k]++;
				}
			}
			// case 4 �ߺ��ؼ� ��縦 �� ���
			for (int i = 0; i < n; i++)
			{
				if (visit[i] > 1)
				{
					check = false;
					break;
				}
			}
		}
		if (check == true)
		{
			result++;
			/*cout << i << "��\n";*/
		}
	}
	cout << result;
}