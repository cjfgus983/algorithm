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
	int swapindex = -1;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		for (int j = arr.size() - 1; j >= i+1; j--)
		{
			if (arr[i] > arr[j]) // 앞에것이 뒤에보다 크다면
			{
				if (flag < i) // 직전에 지정한거보다 탐색이 크면
				{
					flag = i;
					swapindex = j;
				}
				break;
			}
		}
	}
	if (flag == -1)
	{
		cout << -1;
		return 0;
	}
	swap(arr[flag], arr[swapindex]);
	// 정렬
	sort(arr.begin() + flag + 1, arr.end(), greater<int>());
	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}