#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> input(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	// dp
	vector<int> dp(n + 1, -9999);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = input[i];
	}
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + input[i]);
	}
	// 출력
	int result = -9999;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}
	cout << result;
}