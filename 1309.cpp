#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	vector<vector<int>> dp(n + 1,vector<int>(3,0));
	dp[1][0] = 1; // 1행에 하나도 없는 경우
	dp[1][1] = 1; // 1행에 왼쪽에 있는 경우
	dp[1][2] = 1; // 1행에 오른쪽에 있는 경우

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2])%9901;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2])%9901;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
	}
	int result = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
	cout << result;
}