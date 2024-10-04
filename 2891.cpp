#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s, r;
	cin >> n >> s >> r;

	vector<int> cnt(n + 1, 1);

	// ���峭 ��
	for (int i = 1; i <= s; i++)
	{
		int a;
		cin >> a;
		cnt[a]--;
	}
	// �� ���� ��
	for (int i = 1; i <= r; i++)
	{
		int a;
		cin >> a;
		cnt[a]++;
	}
	// �����ֱ�
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
	// �� �� ã�ƺ���
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



