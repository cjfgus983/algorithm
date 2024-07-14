#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[8];

bool permutation()
{
	int swapFront = -1;
	int swapBack = -1;
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j] < arr[i]) // 앞에 더 작은게 있다면
			{
				if (j > swapFront)
				{
					swapFront = j;
					swapBack = i;
				}
			}
		}
	}
	if (swapFront == -1)
		return false;
	else
	{
		swap(arr[swapFront], arr[swapBack]);
		sort(arr + swapFront + 1, arr + n);
	}
	return true;
	
}

int main()
{
	//입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	// 출력
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	while (permutation())
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
}