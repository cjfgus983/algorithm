#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> input;
vector<int> result;

int main()
{
	cin >> n;
	input = vector<int>(n * 2);
	for (int i = 0; i < n * 2; i++)
	{
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	for (int i = 0; i < n; i++)
	{
		int tmp = input[i] + input[2 * n - i - 1];
		result.push_back(tmp);
	}
	sort(result.begin(), result.end());
	cout << result[0];
}