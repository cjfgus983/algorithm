#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(100001, 9999);
	dp[1] = 1;
	// dp
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j*j <= i; j++)
		{
			if (i == j * j)
			{
				dp[i] = 1;
				break;
			}
			dp[i] = min(dp[i],dp[i - j * j] + 1);
		}
	}

	cout << dp[n];
}