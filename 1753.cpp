//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int v, e, start;
//vector<vector<pair<int, int>>> rel(20001);  // ���� ����Ʈ (������, ����ġ)
//vector<int> weight(20001, INT_MAX);         // �ִ� �Ÿ��� �����ϴ� �迭
//
//void dijkstra(int start)
//{
//    // �켱���� ť (����ġ, ���)�� �����Ǹ�, ���� ���� ����ġ�� ���� ��尡 ���� ó����
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    weight[start] = 0;  // ���� ����� ����ġ�� 0
//    pq.push({ 0, start });  // (����ġ, ���)
//
//    while (!pq.empty()) {
//        int now_weight = pq.top().first;
//        int now_node = pq.top().second;
//        pq.pop();
//
//        // �̹� ���� �ִ� �Ÿ����� ũ�� �н�
//        if (now_weight > weight[now_node])
//            continue;
//
//        for (int i = 0; i < rel[now_node].size(); i++) {
//            int next_node = rel[now_node][i].first;   // ���� ���
//            int edge_weight = rel[now_node][i].second;  // ���� ����ġ
//
//            // �� ª�� ��� �߰� �� ������Ʈ
//            if (weight[next_node] > weight[now_node] + edge_weight) {
//                weight[next_node] = weight[now_node] + edge_weight;
//                pq.push({ weight[next_node], next_node });
//            }
//        }
//    }
//}
//
//int main()
//{
//    // �Է�
//    cin >> v >> e;
//    cin >> start;
//
//    for (int i = 0; i < e; i++) {
//        int s, e, w;
//        cin >> s >> e >> w;
//        rel[s].push_back({ e, w });  // s���� e�� ���� ����ġ w�� ����
//    }
//
//    // ���ͽ�Ʈ�� �˰��� ����
//    dijkstra(start);
//
//    // ��� ���
//    for (int i = 1; i <= v; i++) {
//        if (weight[i] == INT_MAX) {
//            cout << "INF\n";  // ������ �� ���� ���
//        }
//        else {
//            cout << weight[i] << '\n';  // �ִ� �Ÿ� ���
//        }
//    }
//
//    return 0;
//}



#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int v, e, start;
vector < vector<pair<int, int>>> rel(20001);  // (���� node, ����ġ) 
vector<int> weight(20001, INT_MAX);

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (����ġ, node) ����ġ�� �������� ��������
	weight[start] = 0;
	pq.push({ weight[start], start });
	while (!pq.empty())
	{
		int now_weight = pq.top().first; // ������ �ϴ� node �� ����ġ
		int now_node = pq.top().second; // ������ �ϴ� node
		pq.pop();

		if (now_weight > weight[now_node])
			continue;

		for (int i = 0; i < rel[now_node].size(); i++)
		{
			int next_node = rel[now_node][i].first;
			int next_weight = rel[now_node][i].second;
			if (weight[next_node] > weight[now_node] + next_weight)
			{
				weight[next_node] = weight[now_node] + next_weight;
				pq.push({weight[now_node],next_node});
			}
		}
	}
}

int main()
{
	cin >> v >> e >> start;
	for (int i = 0; i < e; i++)
	{
		int first, second, w;
		cin >> first >> second >> w;
		rel[first].push_back(make_pair(second, w));
	}

	dijkstra(start);

	for (int i = 1; i <= v; i++) {
		if (weight[i] == INT_MAX) {
			cout << "INF\n";  // ������ �� ���� ���
		}
		else {
			cout << weight[i] << '\n';  // �ִ� �Ÿ� ���
		}
	}
}