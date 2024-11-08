#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map(18, vector<int>(6, 0));
vector<vector<bool>> visit(18, vector<bool>(6, 0));

vector<bool> dice(6, false);
// 바닥 / 상 / 하 / 좌 / 우 / 천장

// 상 하 좌 우 로 탐색
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

bool result[3] = { true, true, true };

void down()
{
	vector<bool> tmp = dice;
	dice[0] = tmp[2];
	dice[2] = tmp[5];
	dice[5] = tmp[1];
	dice[1] = tmp[0];

}

void up()
{
	vector<bool> tmp = dice;
	dice[0] = tmp[1];
	dice[1] = tmp[5];
	dice[5] = tmp[2];
	dice[2] = tmp[0];
}

void left()
{
	vector<bool> tmp = dice;
	dice[0] = tmp[4];
	dice[4] = tmp[5];
	dice[5] = tmp[3];
	dice[3] = tmp[0];
}

void right()
{
	vector<bool> tmp = dice;
	dice[0] = tmp[3];
	dice[3] = tmp[5];
	dice[5] = tmp[4];
	dice[4] = tmp[0];
}

void dfs(int nowR, int nowC, int k)
{
	dice[0] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextR = nowR + dr[i];
		int nextC = nowC + dc[i];

		if (nextR < 0 || nextC < 0 || nextR >= 6 * k || nextC >= 6) // 범위 벗어나면 아웃
			continue;
		if (map[nextR][nextC] == 0) // 전개도가 아니라면 패스
			continue;
		if (visit[nextR][nextC] == true) // 방문했으면 패스
			continue;

		if (i == 0)
			up();
		if(i == 1)
			down();
		if (i == 2)
			left();
		if (i == 3)
			right();

		dice[0] = true; // 바닥면을 트루로
		visit[nextR][nextC] = true;
		dfs(nextR, nextC, k);

		if (i == 0)
			down();
		if (i == 1)
			up();
		if (i == 2)
			right();
		if (i == 3)
			left();
	}
	return;
}

int main()
{
	// 입력
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}
	// 처음 검색
	int nowR = 0;
	int nowC = 0;
	int flag = false;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				nowR = i;
				nowC = j;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	visit[nowR][nowC] = true;
	dfs(nowR, nowC, 1);

	for (int i = 0; i < 6; i++)
	{
		if (dice[i] == false)
		{
			result[0] = false;
		}
	}

	fill(dice.begin(), dice.end(), false);
	flag = false;

	// 2번째 검색

	for (int i = 6; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				nowR = i;
				nowC = j;
				flag = true;
				break;
			}
		}
		if(flag)
			break;
	}
	visit[nowR][nowC] = true;
	dfs(nowR, nowC, 2);

	for (int i = 0; i < 6; i++)
	{
		if (dice[i] == false)
		{
			result[1] = false;
		}
	}


	fill(dice.begin(), dice.end(), false);
	// 3번째 검색
	nowR = 0;
	nowC = 0;
	for (int i = 12; i < 18; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				nowR = i;
				nowC = j;
				break;
			}
		}
	}
	visit[nowR][nowC] = true;
	dfs(nowR, nowC, 3);

	for (int i = 0; i < 6; i++)
	{
		if (dice[i] == false)
		{
			result[2] = false;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		if (result[i])
			cout << "yes\n";
		else
			cout << "no\n";
	}
}