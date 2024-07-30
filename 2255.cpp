#include <iostream>

using namespace std;
unsigned long long dp[201][201];

int main()
{
	int n, k;
	cin >> n >> k;


	for (int i = 1; i <= n; i++)
	{
		dp[i][1] = 1;
		for (int j = 2; j <= k; j++)
		{
			if (i == 1)
			{
				dp[i][j] = j;
			}
			else
			{
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
			}
		}
	}
	cout << dp[n][k];
}