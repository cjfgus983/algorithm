#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int row, col;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<vector<int>> visit_count;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void bfs(int startR, int startC)
{
	visit[startR][startC] = true;
	queue<pair<int,int>> q;
	q.push(make_pair(startR,startC));
	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextR = nowR + dr[i];
			int nextC = nowC + dc[i];
			if (nextR < 0 || nextR >= row)
				continue;
			if (nextC < 0 || nextC >= col)
				continue;
			if (visit[nextR][nextC] == true)
				continue;
			if (map[nextR][nextC] == 0)
				continue;
			visit[nextR][nextC] = true;
			visit_count[nextR][nextC] = visit_count[nowR][nowC] + 1;
			q.push(make_pair(nextR, nextC));
		}
	}
}

int main()
{
	// ют╥б
	cin >> row >> col;
	map = vector<vector<int>>(row, vector<int>(col, 0));
	visit = vector<vector<bool>>(row, vector<bool>(col, 0));
	visit_count = vector<vector<int>>(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < col; j++)
		{
			map[i][j] = input[j] - '0';
		}
	}
	visit_count[0][0] = 1;
	bfs(0, 0);
	cout << visit_count[row-1][col-1];
}