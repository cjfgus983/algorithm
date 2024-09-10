#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(31, 0);
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = dp[2] * 3 + 2; // 2�� 4ĭ�� �� ���� �� �ִ� 2���� ���̽�

	// 2���� ��� �þ��....
	for (int i = 6; i <= 30; i = i + 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j = j + 2)
		{
			dp[i] = dp[i] + dp[i - j] * 2;
		}
	}

	cout << dp[n];
}