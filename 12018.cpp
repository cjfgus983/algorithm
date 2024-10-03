#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
	cin >> n >> m;
	vector<int> min_m;
	while(n--)
	{
		int people = 0;
		int canget = 0;
		cin >> people >> canget;
		int rank = people - canget;
		vector<int> arr;
		for (int i = 0; i < people; i++)
		{
			int c;
			cin >> c;
			arr.push_back(c);
		}
		// 자리 비어서 1만 넣어도 될 때
		if (people < canget)
		{
			min_m.push_back(1);
			continue;
		}
		// ===========================
		sort(arr.begin(), arr.end());
		min_m.push_back(arr[rank]);

	}
	sort(min_m.begin(), min_m.end());
	int cnt = 0;
	for (int i = 0; i < min_m.size(); i++)
	{
		if (min_m[i] <= m)
		{
			m = m - min_m[i];
			cnt++;
		}
		else
			break;
	}

	cout << cnt;
}