#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	vector<string> arr;
	vector<int> ranking(10,0);
	vector<bool> check(10, false);

	for (int i = 0; i < r; i++)
	{
		string str;
		cin >> str;
		arr.push_back(str);
	}
	int rank = 1;
	for (int i = c - 2; i >= 0; i--)
	{
		vector<int> tmp;
		for (int j = 0; j < r; j++)
		{
			int kayak = arr[j][i] - '0';
			if (kayak >= 0 && kayak <= 9)
			{
				if (check[kayak] == true)
					continue;
				tmp.push_back(kayak);
				check[kayak] = true;
			}
		}
		if (!tmp.empty())
		{
			for (int k = 0; k < tmp.size(); k++)
			{
				ranking[tmp[k]] = rank;
			}
			rank++;
		}
	}
	for (int i = 1; i <= 9; i++)
	{
		cout << ranking[i] << '\n';
	}
}
