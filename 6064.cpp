#include <iostream>

using namespace std;

int get_count;

int gcd(int x,int y) {
	if (y > x)
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	while ((x % y) != 0)
	{
		x = x % y;
		int tmp = x;
		x = y;
		y = tmp;
	}
	return y;
}

int lcm(int x,int y)
{
	return x * y / gcd(x, y);
}

int main()
{
	cin >> get_count;
	while (get_count--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		int limit = lcm(m, n);

		int result = -1;
		for (int i = x; i <= limit; i = i + m)
		{
			if ((i-y)%n == 0)
			{
				result = i;
				break;
			}
		}
		cout << result << '\n';

	}
}