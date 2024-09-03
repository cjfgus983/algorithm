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

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i-1], max(arr[i] + dp[i-2], arr[i-1] + arr[i] + dp[i-3]));
	}
	// dp[i-1] 는 내가 포함 안되는 경우 ex) 1 1 0
	// arr[i] + dp[i-2] 는 전이 포함 안되는 경우 ex) 1 0 1
	// arr[i-1] + arr[i] + dp[i-3] ex) 0 1 1
	cout << dp[n];
}
