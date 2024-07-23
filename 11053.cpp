#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<int> dp(n + 1, 0);

	// �Է�
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// dp
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] >= dp[i] && arr[j] < arr[i]) // ���� dp�� �� ũ�� // ���� ���� �� ũ��
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	//���
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;
}