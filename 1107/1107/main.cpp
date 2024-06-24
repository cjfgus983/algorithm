#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n; // 이동하고자 하는 채널
int m; // 고장난 버튼 개수
bool ban[10];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		ban[a] = true;
	}

	if (n == 100) // 이미 목표일 때
	{
		cout << 0;
		return 0;
	}
	if (m == 10) // 다 고장 났을 때
	{
		cout << abs(n - 100);
		return 0;
	}
	int upper, lower;
	for (upper = n; upper < 999999; upper++)
	{
		string str = to_string(upper);
		bool pass = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (ban[str[i] - '0']) // 고장난 버튼이 있으면 break
			{
				pass = false;
				break;
			}
		}
		if (pass)
			break;
	}

	for (lower = n; lower >= 0; lower--)
	{
		string str = to_string(lower);
		bool pass = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (ban[str[i] - '0']) // 고장난 버튼이 있으면 break
			{
				pass = false;
				break;
			}
		}
		if (pass)
			break;
	} 
	if (lower < 0) // lower 가 음수가 될 수도 있기 때문에
	{
		lower = 999999;
	}

	int result = min((int)min(abs(n - lower) + to_string(lower).size() , abs(n - upper) + to_string(upper).size()), abs(n - 100));

	cout << result;
	return 0;
}

// 1. 한번에 그 근처로 이동하는 경우
// 1-1. 해당 목표의 위로
// 1-2. 해당 목표의 아래로
// 2. + - 만으로 이동하는 경우
// 3. 100이 들어온 경우
// 4. 다 고장났을 경우