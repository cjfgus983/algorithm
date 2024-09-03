#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] > result)
		{
			result = dp[n][i];
		}
	}

	cout << result;
}