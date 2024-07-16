#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<vector<long long>> dp(100001, vector<long long>(4, 0));
	dp[1][1] = 1; // 1로 끝나는 dp[1]
	dp[2][2] = 1; // 2로 끝나는 dp[2]

	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
			dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
			dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		}
		int result = (dp[n][1] + dp[n][2] + dp[n][3]) % 1000000009;
		cout << result << '\n';
	}
}