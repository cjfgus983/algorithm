#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin,str);
	string find_str;
	getline(cin, find_str);

	int result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < find_str.size(); j++)
		{
			// str[j] ¶û find_str[j] ¶û ºñ±³
			if (j + i > str.size())
			{
				flag = false;
				break;
			}
			if (str[i + j] != find_str[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			i = i + find_str.size() - 1;
			result++;
		}
	}
	cout << result;
}