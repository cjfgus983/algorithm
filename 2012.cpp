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
		result += abs(arr[i] - (i + 1)); // arr[i] 는 예상등수고  i + 1 는 실제 등수
	}
	cout << result;
}