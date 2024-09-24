#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int row, col;
int arr[1001][1001];
int cnt[1001][1001];
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void bfs()
{
	queue<pair <int, int>> q;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
				cnt[i][j] = 0;
			}
		}
	}
	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();
		arr[nowR][nowC] = 1;
		//visit[nowR][nowC] = true;
		for (int i = 0; i < 4; i++)
		{
			int nextR = nowR + dr[i];
			int nextC = nowC + dc[i];
			// 범위 체크
			if (nextR < 0 || nextR >= row)
				continue;
			if (nextC < 0 || nextC >= col)
				continue;
			// 방문 체크
			if (arr[nextR][nextC] == 1)
				continue;
			// 못가는 길 체크
			if (arr[nextR][nextC] == -1)
				continue;
			cnt[nextR][nextC] = cnt[nowR][nowC] + 1;
			q.push(make_pair(nextR, nextC));
		}
	}
	return;
}

int main()
{
	// 입력
	cin >> col >> row;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> arr[i][j];
		}
	}
	bfs();
	int result = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0 && cnt[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
			result = max(result, cnt[i][j]);
		}
	}
	cout << result;
}