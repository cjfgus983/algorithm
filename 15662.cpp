#include <iostream>
#include <vector>

using namespace std;

int t;
vector<vector<int>> arr;

// 2 : 오른쪽
// 6 : 왼쪽

void rotate(int idx)
{
	int tmp = arr[idx][7];
	for (int i = 7; i >=1; i--)
	{
		arr[idx][i] = arr[idx][i - 1];
	}
	arr[idx][0] = tmp;
}

void rotate_reverse(int idx)
{
	int tmp = arr[idx][0];
	for (int i = 0; i <= 6; i++)
	{
		arr[idx][i] = arr[idx][i + 1];
	}
	arr[idx][7] = tmp;
}

int main()
{
	cin >> t;
	arr = vector<vector<int>>(t, vector<int>(8,0));
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = str[j] - '0';
		}
	}

	int k = 0;
	cin >> k;
	while (k--)
	{
		int first, first_rotate;
		cin >> first >> first_rotate;
		first = first - 1;
		vector<int> tmpArr(t, 0);
		tmpArr[first] = first_rotate;

		// 기준점부터 오른쪽 탐색
		for (int i = first + 1; i < t; i++)
		{
			if (arr[i - 1][2] == arr[i][6])
			{
				break;
			}
			else // 회전해야 하는 경우
			{
				if (tmpArr[i - 1] == -1)
					tmpArr[i] = 1;
				else if (tmpArr[i - 1] == 1)
					tmpArr[i] = -1;
			}
		}
		// 기준점부터 왼쪽 탐색
		for (int i = first - 1; i >= 0; i--)
		{
			if (arr[i][2] == arr[i + 1][6])
			{
				break;
			}
			else // 회전해야 하는 경우
			{
				if (tmpArr[i + 1] == -1)
					tmpArr[i] = 1;
				else if (tmpArr[i + 1] == 1)
					tmpArr[i] = -1;
			}
		}
		// 회전 적용
		for (int i = 0; i < t; i++)
		{
			if (tmpArr[i] == -1)
			{
				rotate_reverse(i);
			}
			else if(tmpArr[i] == 1)
				rotate(i);
		}
	}
	int result = 0;
	for (int i = 0; i < t; i++)
	{
		if (arr[i][0] == 1)
			result++;
	}
	cout << result;
}