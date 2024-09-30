#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int k;

int n, m, w; // n ���� m ���� w ��Ȧ
// ���δ� ������ ���� w �� ������ ����
// ��Ȧ������ �ð��� �ݴ�� ��
// ���� ������ �ִ°� 

vector <pair<int, pair<int, int>>> rel;
vector<long long> dist(501, INT_MAX);

bool Bell()
{
	dist[1] = 0;

	// n-1�� �Ұǵ� n�� �� ���� �Ÿ��� �پ��ٸ� ���� ����
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < rel.size(); j++)
		{
			int from = rel[j].first;
			int to = rel[j].second.first;
			int weight = rel[j].second.second;

			if (dist[from] == 10001)
				continue;
			if (dist[to] > dist[from] + weight)
			{
				dist[to] = dist[from] + weight;
				
				if (i == n)
					return true;

			}
		}
	}
	return false;
}

int main()
{
	cin >> k;
	while (k--)
	{
		// �Է�
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			int from, to, weight;
			cin >> from >> to >> weight;
			rel.push_back({ from,{to, weight} });
			rel.push_back({ to,{from, weight} });
		}
		for (int i = 0; i < w; i++)
		{
			int from, to, weight;
			cin >> from >> to >> weight;
			rel.push_back({ from,{to, -weight} });
		}
		if (Bell())
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
		fill(dist.begin(),dist.end(), INT_MAX);
		rel.clear();
	}
}