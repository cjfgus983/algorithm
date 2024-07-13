#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	//�Է�
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//Ž��
	int flag = -1;
	int swapindex = -1;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = arr.size() - 1; j >= i+1; j--)
		{
			if (arr[i] > arr[j]) // �տ����� �ڿ����� ũ�ٸ�
			{
				if (flag < i) // ������ �����Ѱź��� Ž���� ũ��
				{
					flag = i;
					swapindex = j;
				}
				break;
			}
		}
	}
	if (flag == -1)
	{
		cout << -1;
		return 0;
	}
	swap(arr[flag], arr[swapindex]);
	// ����
	sort(arr.begin() + flag + 1, arr.end(), greater<int>());
	// ���
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}