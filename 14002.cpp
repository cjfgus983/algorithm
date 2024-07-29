#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp
int main()
{
	int n;
	cin >> n;
	vector<int> input(n + 1, 0);
	vector<int> dp(n + 1, 0);

	// �Է�
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	// dp
	vector<vector<int>> arr(n + 1);

	dp[1] = 1;
	arr[1].push_back(input[1]);

	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] >= dp[i] && input[j] < input[i]) // ���� dp�� �� ũ�� // ���� ���� �� ũ��
			{
				dp[i] = dp[j] + 1;
				arr[i] = arr[j];
				arr[i].push_back(input[i]);
			}
		}
		if (arr[i].empty()) {
			dp[i] = 1;
			arr[i].push_back(input[i]);
		}
	}

	//���
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result << '\n'; // ���� �� ������ ���̴� result

	for (int i = 1; i <= n; i++)
	{
		if (result == arr[i].size())
		{
			for (int j = 0; j < result; j++)
			{
				cout << arr[i][j] << ' ';
			}
			break;
		}
	}
	cout << endl;
}