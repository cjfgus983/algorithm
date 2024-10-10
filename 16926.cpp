#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, r;
vector < vector<int >> arr;

void Rotate(int block)
{
	for (int k = 0; k < block; k++) // °ã°ã¸¶´Ù È¸Àü ÁøÇà
	{
		int tmp = arr[k][k];
		// À§ÂÊ
		for (int i = k; i <= m - 2 - k; i++)
		{
			arr[k][i] = arr[k][i + 1];
		}
		// ¿À¸¥ÂÊ
		for (int i = k; i <= n - 2 - k; i++)
		{
			arr[i][m - 1 - k] = arr[i + 1][m - 1 - k];
		}
		// ¾Æ·¡ÂÊ
		for (int i = m - 1 - k; i >= 1 + k; i--)
		{
			arr[n - k - 1][i] = arr[n - k - 1][i - 1];
		}
		// ¿ÞÂÊ
		for (int i = n - 1 - k; i >= 1 + k; i--)
		{
			arr[i][k] = arr[i - 1][k];
		}

		arr[k + 1][k] = tmp;
	}
}

int main()
{
	cin >> n >> m >> r;
	arr = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int block = min(n, m) / 2; // °ã
	while (r--)
	{
		Rotate(block);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j]<<' ';
		}
		cout << '\n';
	}
}