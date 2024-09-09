#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i; j >= 0; j--)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(dp[i], result);
	}
	cout << result;
}