#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(10, 0));

	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1; // 자리수가 1인데 i로 끝나는 배열의 개수 = 1
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
			}
		}
	}

	int result = 0;
	for (int i = 0; i <= 9; i++)
	{
		result = (result + dp[n][i])% 10007;
	}
	cout << result;
}