#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int findIndex = 0;
	cin >> findIndex;
	int midx = n / 2;
	int midy = n / 2;

	vector<vector<int>> arr(n, vector<int>(n, 0));
	arr[midy][midx] = 1;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };

	int cnt = 0; // 2가 되면 go를 증가시킴
	int dir = 0; // 매번 dir = (dir + 1) % 4
	int go = 1; // cnt 가 2가 되면 ++
	int index = 2;

	int resultx = midx+1; // 열
	int resulty = midy+1; // 행


	while (index < n * n)
	{
		// 한 방향으로 한번 쭉
		for (int i = 0; i < go; i++)
		{
			midx = midx + dx[dir];
			midy = midy + dy[dir];
			if (midy < 0)
				break;
			arr[midy][midx] = index;
			if (findIndex == index)
			{
				resultx = midx + 1;
				resulty = midy + 1;
			}
			index++;
		}
		cnt++; // 2가 되었을 떄 go 를 증가시켜야
		dir = (dir + 1) % 4; // 방향 바꾸고
		if (cnt == 2)
		{
			cnt = 0;
			go++;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << resulty << ' ' << resultx;

}