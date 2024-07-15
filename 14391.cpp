#include <iostream>
#include <algorithm>

using namespace std;

int n; // 행 길이
int m; // 열 길이
int arr[4][4];
bool isRow[4][4]; // 해당 타일은 가로로 계산
int result = 0;

void dfs(int r, int c)
{
	if (r == n) // r이 n이 됐다는 것은 끝까지 다 돌았다는 것.
	{
		int total = 0;
		// 가로 계산
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < m; j++)
			{
				if (isRow[i][j] == true) // 가로처리라면
				{
					sum = sum * 10 + arr[i][j];
				}
				else // 세로처리라면
				{
					total = total + sum;
					sum = 0;
				}
			}
			total = total + sum;
		}
		// 세로 계산
		for (int j = 0; j < m; j++)
		{
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				if (isRow[i][j] == false) // 세로처리라면
				{
					sum = sum * 10 + arr[i][j];
				}
				else // 가로처리라면
				{
					total = total + sum;
					sum = 0;
				}
			}
			total = total + sum;
		}
		result = max(total, result);
		return;
	}
	if (c == m) // 열을 다 돌았으면 다음 행으로
	{
		dfs(r + 1, 0);
		return;
	}

	//해당 타일은 한번은 가로로, 한번은 세로로 계산
	isRow[r][c] = true;
	dfs(r, c + 1);
	isRow[r][c] = false;
	dfs(r, c + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%1d", &arr[i][j]);
		}
	}
	dfs(0, 0);
	cout << result;
}