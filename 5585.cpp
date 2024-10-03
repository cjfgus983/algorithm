#include <iostream>

using namespace std;

int n = 0;

int main()
{
	cin >> n;
	int need = 1000 - n;
	int result = 0;
	if (need / 500 > 0)
	{
		int num;
		num = need / 500;
		need = need - 500 * num;
		result += num;
	}
	if (need / 100 > 0)
	{
		int num = 0;
		num = need / 100;
		need = need - 100 * num;
		result += num;
	}
	if (need / 50 > 0)
	{
		int num;
		num = need / 50;
		need = need - 50 * num;
		result += num;
	}
	if (need / 10 > 0)
	{
		int num;
		num = need / 10;
		need = need - 10 * num;
		result += num;
	}
	if (need / 5 > 0)
	{
		int num;
		num = need / 5;
		need = need - 5 * num;
		result += num;
	}
	if (need / 1 > 0)
	{
		int num;
		num = need / 1;
		need = need - 1 * num;
		result += num;
	}
	cout << result;
}