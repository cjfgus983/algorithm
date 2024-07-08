#include <iostream>
#include <algorithm>

using namespace std;

int t[16];
int p[16];
int dp[16];
int result = 0;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == j + t[j])
				dp[i] = max(dp[i], dp[j] + p[j]);
			else
				dp[i] = max(dp[i], dp[j]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}
	cout << result;
}