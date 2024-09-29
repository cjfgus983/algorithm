//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int v, e, start;
//vector<vector<pair<int, int>>> rel(20001);  // 인접 리스트 (목적지, 가중치)
//vector<int> weight(20001, INT_MAX);         // 최단 거리를 저장하는 배열
//
//void dijkstra(int start)
//{
//    // 우선순위 큐 (가중치, 노드)로 구성되며, 가장 작은 가중치를 가진 노드가 먼저 처리됨
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    weight[start] = 0;  // 시작 노드의 가중치는 0
//    pq.push({ 0, start });  // (가중치, 노드)
//
//    while (!pq.empty()) {
//        int now_weight = pq.top().first;
//        int now_node = pq.top().second;
//        pq.pop();
//
//        // 이미 계산된 최단 거리보다 크면 패스
//        if (now_weight > weight[now_node])
//            continue;
//
//        for (int i = 0; i < rel[now_node].size(); i++) {
//            int next_node = rel[now_node][i].first;   // 다음 노드
//            int edge_weight = rel[now_node][i].second;  // 간선 가중치
//
//            // 더 짧은 경로 발견 시 업데이트
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
//    // 입력
//    cin >> v >> e;
//    cin >> start;
//
//    for (int i = 0; i < e; i++) {
//        int s, e, w;
//        cin >> s >> e >> w;
//        rel[s].push_back({ e, w });  // s에서 e로 가는 가중치 w의 간선
//    }
//
//    // 다익스트라 알고리즘 실행
//    dijkstra(start);
//
//    // 결과 출력
//    for (int i = 1; i <= v; i++) {
//        if (weight[i] == INT_MAX) {
//            cout << "INF\n";  // 도달할 수 없는 경우
//        }
//        else {
//            cout << weight[i] << '\n';  // 최단 거리 출력
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
vector < vector<pair<int, int>>> rel(20001);  // (연결 node, 가중치) 
vector<int> weight(20001, INT_MAX);

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (가중치, node) 가중치를 기준으로 오름차순
	weight[start] = 0;
	pq.push({ weight[start], start });
	while (!pq.empty())
	{
		int now_weight = pq.top().first; // 가고자 하는 node 의 가중치
		int now_node = pq.top().second; // 가고자 하는 node
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
			cout << "INF\n";  // 도달할 수 없는 경우
		}
		else {
			cout << weight[i] << '\n';  // 최단 거리 출력
		}
	}
}