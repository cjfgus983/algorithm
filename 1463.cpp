#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000000];

int main()
{
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i <= n; i++)
	{
		int tmp1 = 9999;
		int tmp2 = 9999;
		int tmp3 = dp[i-1];
		if (i % 2 == 0)
			tmp1 = dp[i / 2];
		if (i % 3 == 0)
			tmp2 = dp[i / 3];
		dp[i] = min(tmp1, min(tmp2, tmp3)) + 1;
	}
	cout << dp[n];
}