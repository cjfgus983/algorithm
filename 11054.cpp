#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	//
	vector<int> dp_up(n + 1, 1);
	vector<int> dp_down(n + 1, 0);

	// 증가하는 수열
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp_up[i] = max(dp_up[i], dp_up[j] + 1);
			}
		}
	}

	// 감소하는 수열
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = n; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				dp_down[i] = max(dp_down[i], dp_down[j] + 1);
			}
		}
	}

	// 합치기
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp_up[i] + dp_down[i]);
	}

	cout << result;
}