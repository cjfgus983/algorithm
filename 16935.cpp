#include <iostream>
#include <vector>

using namespace std;
int n, m, r;
vector<vector<int>> arr;

void Rotate1()
{
	vector<vector<int>> tmp = arr;
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[n - 1 - i];
	}
	arr = tmp;
}

void Rotate2()
{
	vector<vector<int>> tmp = arr;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = arr[i][m - 1 - j];
		}
	}
	arr = tmp;
}

void Rotate3()
{
	vector<vector<int>> tmp(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[j][i] = arr[i][j];
		}
	}
	arr = tmp;
	int tmp_num = n;
	n = m;
	m = tmp_num;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = arr[i][m - 1 - j];
		}
	}
	arr = tmp;
}

void Rotate4()
{
	vector<vector<int>> tmp(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[j][i] = arr[i][j];
		}
	}
	arr = tmp;
	int tmp_num = n;
	n = m;
	m = tmp_num;
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[n - 1 - i];
	}
	arr = tmp;
}

void Rotate5()
{
	int midn = n / 2;
	int midm = m / 2;
	vector<vector<int>> tmp = arr;
	// 1 -> 2
	for (int i = 0; i < midn; i++)
	{
		for (int j = midm; j < m; j++)
		{
			tmp[i][j] = arr[i][j-midm];
		}
	}
	// 2 -> 3
	for (int i = midn; i < n; i++)
	{
		for (int j = midm; j < m; j++)
		{
			tmp[i][j] = arr[i-midn][j];
		}
	}
	// 3 -> 4
	for (int i = midn; i < n; i++)
	{
		for (int j = 0; j < midm; j++)
		{
			tmp[i][j] = arr[i][j + midm];
		}
	}
	// 4 -> 1
	for (int i = 0; i < midn; i++)
	{
		for (int j = 0; j < midm; j++)
		{
			tmp[i][j] = arr[i + midn][j];
		}
	}
	arr = tmp;
}

void Rotate6()
{
	int midn = n / 2;
	int midm = m / 2;
	vector<vector<int>> tmp = arr;
	// 3 -> 2
	for (int i = 0; i < midn; i++)
	{
		for (int j = midm; j < m; j++)
		{
			tmp[i][j] = arr[midn + i][j];
		}
	}
	// 4 -> 3
	for (int i = midn; i < n; i++)
	{
		for (int j = midm; j < m; j++)
		{
			tmp[i][j] = arr[i][j - midm];
		}
	}
	// 1 -> 4
	for (int i = midn; i < n; i++)
	{
		for (int j = 0; j < midm; j++)
		{
			tmp[i][j] = arr[i - midn][j];
		}
	}
	// 2 -> 1
	for (int i = 0; i < midn; i++)
	{
		for (int j = 0; j < midm; j++)
		{
			tmp[i][j] = arr[i][j + midm];
		}
	}
	arr = tmp;
}

int main()
{
	// 입력
	cin >> n >> m >> r;
	arr = vector<vector<int>>(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < r; i++)
	{
		int rCase = 0;
		cin >> rCase;
		if (rCase == 1)
		{
			Rotate1();
		}
		if (rCase == 2)
		{
			Rotate2();
		}
		if (rCase == 3)
		{
			Rotate3();
		}
		if (rCase == 4)
		{
			Rotate4();
		}
		if (rCase == 5)
		{
			Rotate5();
		}
		if (rCase == 6)
		{
			Rotate6();
		}
	}



	//결과 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

}