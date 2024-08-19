#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long long> dp(1000001, 0);

int main()
{
	int t;
	cin >> t;
	dp[1] = 1; // 1
	dp[2] = 2; // 11 2
	dp[3] = 4; // 111 21 12 3
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
		}
		cout << dp[n] << '\n';
	}
}