#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long x, y; // 집의 위치
int w, s; // 가로세로, 대각선
long long result = 0;

int main()
{
	cin >> x >> y >> w >> s;

	long long case_A = (x + y) * w; 
	long long case_B = min(x, y) * s; // 대각선으로 갈 수 있는 만큼은 이동

	long long caseB1; // 남은거는 그냥 가로 세로로 이동
	long long caseB2; // 남은거를 대각선으로 이동
	
	caseB1 = abs(x - y) * w;
	if ((x + y) % 2 == 0) // 짝수
	{
		caseB2 = abs(x - y) * s;
	}
	else // 홀수
	{
		caseB2 = (abs(x - y) - 1) * s + w;
	}
	case_B = case_B + min(caseB1, caseB2);

	result = min(case_A, case_B);
	cout << result;
}