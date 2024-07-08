#include <iostream>
#include <algorithm>

using namespace std;

int l, c;
char arr[15];
char result[15];
bool visit[15];

void dfs(int cnt, int start)
{
	if (cnt == l)
	{
		bool succed = false;
		int v_count = 0;
		for (int i = 0; i < l; i++)
		{
			if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u')
				v_count++;
		}
		if (v_count >= 1 && l - v_count >= 2)
			succed = true;
		if (succed)
		{
			for (int i = 0; i < l; i++)
			{
				cout << result[i];
			}
			cout << '\n';
		}
	}

	for (int i = start; i < c; i++)
	{
		visit[i] = true;
		result[cnt] = arr[i];
		dfs(cnt + 1, i + 1);
		visit[i] = false;
	}
}

int main()
{
	cin >> l >> c;
	//암호는 최소 1개의 모음, 2개의 자음, 증가하는 순서
	for (int i = 0; i < c; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + c);

	dfs(0, 0);
}