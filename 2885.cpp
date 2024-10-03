#include <iostream>

using namespace std;

int k;

int cnt = 0;

void check(int now_size, int pick)
{
	while (now_size != k)
	{
		pick = pick / 2;
		if (pick <= k - now_size)
		{
			now_size = now_size + pick;
		}
		cnt++;
	}
}

int main()
{
	cin >> k;

	int pick = 1;
	while (1)
	{
		if (pick >= k)
		{
			break;
		}
		pick = pick * 2;
	}
	if(pick != k)
		check(0, pick);
	cout << pick << ' ' << cnt;
}