#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// dp
int main()
{
	int n;
	cin >> n;
	vector<int> input(n + 1, 0);
	vector<int> dp(n + 1, 0);

	// 입력
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}

	// dp
	vector<vector<int>> arr(n + 1);

	dp[1] = 1;
	arr[1].push_back(input[1]);

	for (int i = 2; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (dp[j] >= dp[i] && input[j] < input[i]) // 앞의 dp가 더 크고 // 현재 값이 더 크면
			{
				dp[i] = dp[j] + 1;
				arr[i] = arr[j];
				arr[i].push_back(input[i]);
			}
		}
		if (arr[i].empty()) {
			dp[i] = 1;
			arr[i].push_back(input[i]);
		}
	}

	//출력
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp[i]);
	}

	cout << result << '\n'; // 가장 긴 수열의 길이는 result

	for (int i = 1; i <= n; i++)
	{
		if (result == arr[i].size())
		{
			for (int j = 0; j < result; j++)
			{
				cout << arr[i][j] << ' ';
			}
			break;
		}
	}
	cout << endl;
}