#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<int> dp(n + 1, 0);

	// 입력
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// dp
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] >= dp[i] && arr[j] < arr[i]) // 앞의 dp가 더 크고 // 현재 값이 더 크면
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	//출력
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result;
}