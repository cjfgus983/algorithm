#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main()
{
	cin >> n;

	vector<int> p(n + 1, 10000);
	vector<int> dp(n + 1, 10000);

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	// p[i] = i개의 카드가 들어있는 카드팩의 가격
	dp[0] = 0;
	p[0] = 0;
	dp[1] = p[1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[n];
}