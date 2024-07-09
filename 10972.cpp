#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main()
{
	//입력
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	//탐색
	int flag = -1;
	int swapi = -1;
	for (int i = arr.size() - 1; i > 0; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i]) // 앞에것이 뒤에보다 작다면
			{
				if (flag < j)
				{
					flag = j;
					swapi = i;
				}
				break;
			}
		}
	}
	swap(arr[flag], arr[swapi]);
	if (flag == -1)
	{
		cout << -1;
		return 0;
	}
	// 정렬
	sort(arr.begin() + flag + 1, arr.end());
	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}