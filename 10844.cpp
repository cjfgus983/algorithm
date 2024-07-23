#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	unsigned long long dp[101][10] = {0};
	// 1일때 초기화
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	// dp
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	// 출력
	unsigned long long result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result = (result + dp[n][i]) % 1000000000;
	}
	cout << result;
}