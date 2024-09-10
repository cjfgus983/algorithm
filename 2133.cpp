#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(31, 0);
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = dp[2] * 3 + 2; // 2는 4칸일 때 나올 수 있는 2가지 케이스

	// 2개씩 계속 늘어나네....
	for (int i = 6; i <= 30; i = i + 2)
	{
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j = j + 2)
		{
			dp[i] = dp[i] + dp[i - j] * 2;
		}
	}

	cout << dp[n];
}