#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;
	vector<int> arr(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	int result = dp[1]; // dp[1]으로 초기화
	for (int i = 1; i <= n; i++)
	{
		if (dp[i] > result)
		{
			result = dp[i];
		}
	}
	cout << result;
}