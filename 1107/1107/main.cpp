#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n; // �̵��ϰ��� �ϴ� ä��
int m; // ���峭 ��ư ����
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

	if (n == 100) // �̹� ��ǥ�� ��
	{
		cout << 0;
		return 0;
	}
	if (m == 10) // �� ���� ���� ��
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
			if (ban[str[i] - '0']) // ���峭 ��ư�� ������ break
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
			if (ban[str[i] - '0']) // ���峭 ��ư�� ������ break
			{
				pass = false;
				break;
			}
		}
		if (pass)
			break;
	} 
	if (lower < 0) // lower �� ������ �� ���� �ֱ� ������
	{
		lower = 999999;
	}

	int result = min((int)min(abs(n - lower) + to_string(lower).size() , abs(n - upper) + to_string(upper).size()), abs(n - 100));

	cout << result;
	return 0;
}

// 1. �ѹ��� �� ��ó�� �̵��ϴ� ���
// 1-1. �ش� ��ǥ�� ����
// 1-2. �ش� ��ǥ�� �Ʒ���
// 2. + - ������ �̵��ϴ� ���
// 3. 100�� ���� ���
// 4. �� ���峵�� ���