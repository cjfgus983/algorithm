#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;
int dx[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dy[8] = { 2,-2,1,-1,2,-2,1,-1 };
vector<vector<bool>> visit(300, vector<bool>(300, false));
vector<vector<int>> visit_cnt(300, vector<int>(300, 0));

void bfs(int startR, int startC, int range, int endR, int endC)
{
	visit[startR][startC] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(startR, startC));
	while (!q.empty())
	{
		int nowR = q.front().first;
		int nowC = q.front().second;
		q.pop();
		if (nowR == endR && nowC == endC)
		{
			cout << visit_cnt[nowR][nowC] << '\n';
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			int nextR = nowR + dx[i];
			int nextC = nowC + dy[i];
			if (nextR < 0 || nextR >= range || nextC < 0 || nextC >= range) // 범위 검사
				continue;
			if (visit[nextR][nextC] == true) // 방문 검사
				continue;
			visit[nextR][nextC] = true;
			q.push(make_pair(nextR, nextC));
			visit_cnt[nextR][nextC] = visit_cnt[nowR][nowC] + 1;
		}
	}
}

int main()
{
	// 입력
	cin >> T;
	while (T--)
	{
		int  l;
		cin >> l;
		int startR, startC; // 출발지점
		cin >> startR >> startC;
		int endR, endC; // 도착지점
		cin >> endR >> endC;
		// 초기화
		for (int i = 0; i < l; i++)
		{
			fill(visit_cnt[i].begin(), visit_cnt[i].end(), 0);
			fill(visit[i].begin(), visit[i].end(), false);
		}

		bfs(startR, startC, l, endR, endC);
	}
}