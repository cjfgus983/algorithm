#include <iostream>
#include <vector>

using namespace std;

int n, m;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int result = 0;
int arr[500][500];
bool visit[500][500];

void dfs(int count, int sum, int row, int col)
{
	if (count == 4)
	{
		if (result < sum)
		{
			result = sum;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int next_row = row + dx[i];
		int next_col = col + dy[i];
		if (next_row < 0 || next_col < 0 || next_row >= n || next_col >= m) // 범위 벗어나면
			continue;
		if (visit[next_row][next_col]) // 방문햇어도 스킵
			continue;
		visit[next_row][next_col] = true;
		dfs(count + 1, sum + arr[next_row][next_col], next_row, next_col);
		visit[next_row][next_col] = false;
	}
}


void Tshape(int row, int col) {
	int sum;

	// ㅗ 모양
	if (row - 1 >= 0 && col - 1 >= 0 && col + 1 < m) {
		sum = arr[row][col] + arr[row - 1][col] + arr[row][col - 1] + arr[row][col + 1];
		if (sum > result) result = sum;
	}

	// ㅜ 모양
	if (row + 1 < n && col - 1 >= 0 && col + 1 < m) {
		sum = arr[row][col] + arr[row + 1][col] + arr[row][col - 1] + arr[row][col + 1];
		if (sum > result) result = sum;
	}

	// ㅓ 모양
	if (row - 1 >= 0 && row + 1 < n && col + 1 < m) {
		sum = arr[row][col] + arr[row - 1][col] + arr[row + 1][col] + arr[row][col + 1];
		if (sum > result) result = sum;
	}

	// ㅏ 모양
	if (row - 1 >= 0 && row + 1 < n && col - 1 >= 0) {
		sum = arr[row][col] + arr[row - 1][col] + arr[row + 1][col] + arr[row][col - 1];
		if (sum > result) result = sum;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = true;
			dfs(0,0,i,j);
			visit[i][j] = false;
			Tshape(i, j);
		}
	}
	cout << result;
}