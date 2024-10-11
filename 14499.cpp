#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> dice(6, 0);
//dice[0] = 윗면
//dice[1] = // 위 기준 상
//dice[2] = // 위 기준 바닥
//dice[3] = // 위 기준 아래
//dice[4] = // 위 기준 왼쪽
//dice[5] = // 위 기준 오른쪽

int dc[4] = { 1,-1,0,0 }; // 오 왼 상 하 
int dr[4] = { 0,0,-1,1 };
vector<vector<int>> map;

void Roll(int dir)
{
	// 오른쪽 이동
	if (dir == 1)
	{
		vector<int> tmp = dice;
		tmp[5] = dice[0];
		tmp[2] = dice[5];
		tmp[4] = dice[2];
		tmp[0] = dice[4];
		dice = tmp;
	}
	// 왼쪽 이동
	if (dir == 2)
	{
		vector<int> tmp = dice;
		tmp[0] = dice[5];
		tmp[5] = dice[2];
		tmp[2] = dice[4];
		tmp[4] = dice[0];
		dice = tmp;
	}
	// 위쪽 이동
	if (dir == 3)
	{
		vector<int> tmp = dice;
		tmp[0] = dice[3];
		tmp[1] = dice[0];
		tmp[2] = dice[1];
		tmp[3] = dice[2];
		dice = tmp;
	}
	// 아래쪽 이동
	if (dir == 4)
	{
		vector<int> tmp = dice;
		tmp[0] = dice[1];
		tmp[1] = dice[2];
		tmp[2] = dice[3];
		tmp[3] = dice[0];
		dice = tmp;
	}
}

int main()
{
	int r, c, nowR, nowC, k;
	cin >> r >> c >> nowR >> nowC >> k;
	map = vector<vector<int>>(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	queue<int> q;
	while (k--)
	{
		int c;
		cin >> c;
		q.push(c);
	}
	while (!q.empty())
	{
		int dir = q.front();
		q.pop();
		int nextR = nowR + dr[dir - 1];
		int nextC = nowC + dc[dir - 1];
		if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) // 범위 벗어나면 아무것도 x
		{
			continue;
		}
		else
		{
			Roll(dir);
			if (map[nextR][nextC] > 0)
			{
				dice[2] = map[nextR][nextC];
				map[nextR][nextC] = 0;
			}
			else if(map[nextR][nextC] == 0)
			{
				map[nextR][nextC] = dice[2];
			}
			cout << dice[0] << '\n';
			nowC = nextC;
			nowR = nextR;
		}
	}
}