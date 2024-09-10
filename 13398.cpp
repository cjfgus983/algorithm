#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	// �Է�
	int n = 0;
	cin >> n;
	vector<int> arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	//
	vector<int> dp_left(n + 2, -1000);
	vector<int> dp_right(n + 2, -1000);
	vector<int> dp_result(n + 2, -1000);
	
	// �ڽ� ���� ���� �ִ� ��
	for (int i = 1; i <= n; i++)
	{
		dp_left[i] = arr[i];
		dp_left[i] = max(dp_left[i], dp_left[i - 1] + arr[i]);
	}
	// �ڽ� ���� ������ �ִ� ��
	for (int i = n; i >=1; i--)
	{
		dp_right[i] = arr[i];
		dp_right[i] = max(dp_right[i], dp_right[i + 1] + arr[i]);
	}
	// �ִ밪 ã�� 
	// �ڽ��� �A �� vs �ڽ��� ���� ��
	for (int i = 1; i <= n; i++)
	{
		dp_result[i] = max(dp_left[i] + dp_right[i] - arr[i], dp_left[i - 1] + dp_right[i + 1]);
	}

	// ���
	int result = INT_MIN;
	for (int i = 1; i <= n; i++)
	{
		result = max(result, dp_result[i]);
	}
	cout << result;
}