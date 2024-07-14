#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[9];
bool check[9];
int sum;
int tmp[9];
int biggest;

void dfs(int count)
{
	if (count == N)
	{
		sum = 0;
		for (int i = 0; i < N - 1; i++)
		{
			sum = sum + abs(tmp[i] - tmp[i + 1]);
		}
		biggest = max(biggest, sum);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (check[i])
			continue;
		check[i] = true;
		tmp[i] = arr[i];
		dfs(count + 1);
		check[i] = false;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	dfs(0);
	cout << biggest;
}