#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s, r;
	cin >> n >> s >> r;

	vector<int> cnt(n + 1, 1);

	// 고장난 것
	for (int i = 1; i <= s; i++)
	{
		int a;
		cin >> a;
		cnt[a]--;
	}
	// 더 가진 것
	for (int i = 1; i <= r; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	// 나눠주기
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 2)
		{
			if (i-1 >= 1 && cnt[i - 1] == 0)
			{
				cnt[i - 1]++;
				cnt[i]--;
				continue;
			}
			if (i+1 <= n && cnt[i + 1] == 0)
			{
				cnt[i + 1]++;
				cnt[i]--;
				continue;
			}
		}
	}
	// 빈 곳 찾아보기
	int result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 0)
		{
			result++;
		}
	}
	cout << result;
}



