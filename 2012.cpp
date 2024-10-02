#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<int> arr;

int main()
{
	cin >> n;
	arr = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	long long result = 0;
	for (int i = 0; i < n; i++)
	{
		result += abs(arr[i] - (i + 1)); // arr[i] �� ��������  i + 1 �� ���� ���
	}
	cout << result;
}