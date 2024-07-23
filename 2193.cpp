#include <iostream>

using namespace std;

int main()
{
	long long dp[91][2] = { 0 };
	// 입력
	int n;
	cin >> n;

	// dp
	dp[1][1] = 1;
	dp[1][0] = 0;

	dp[2][0] = dp[1][1] + dp[1][0];
	dp[2][1] = dp[1][0];

	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		dp[i][1] = dp[i-1][0];
	}
	
	// 출력
	cout << dp[n][0] + dp[n][1];
}