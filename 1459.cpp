#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long x, y; // ���� ��ġ
int w, s; // ���μ���, �밢��
long long result = 0;

int main()
{
	cin >> x >> y >> w >> s;

	long long case_A = (x + y) * w; 
	long long case_B = min(x, y) * s; // �밢������ �� �� �ִ� ��ŭ�� �̵�

	long long caseB1; // �����Ŵ� �׳� ���� ���η� �̵�
	long long caseB2; // �����Ÿ� �밢������ �̵�
	
	caseB1 = abs(x - y) * w;
	if ((x + y) % 2 == 0) // ¦��
	{
		caseB2 = abs(x - y) * s;
	}
	else // Ȧ��
	{
		caseB2 = (abs(x - y) - 1) * s + w;
	}
	case_B = case_B + min(caseB1, caseB2);

	result = min(case_A, case_B);
	cout << result;
}