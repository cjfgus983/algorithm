#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> r;
vector<int> g;
vector<int> b;

int main()
{
	cin >> n;
	r = vector<int>(n+1,0);
	g = vector<int>(n+1,0);
	b = vector<int>(n+1,0);

	for (int i = 1; i <= n; i++)
	{
		cin >> r[i] >> g[i] >> b[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(4, 0));
	
	dp[1][1] = r[1];
	dp[1][2] = g[1];
	dp[1][3] = b[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = min(dp[i - 1][2] + r[i], dp[i - 1][3] + r[i]);
		dp[i][2] = min(dp[i - 1][1] + g[i], dp[i - 1][3] + g[i]);
		dp[i][3] = min(dp[i - 1][1] + b[i], dp[i - 1][2] + b[i]);
	}

	int result = min(dp[n][1], min(dp[n][2], dp[n][3]));

	cout << result;
}