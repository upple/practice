#include <iostream>
#include <vector>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;

vector<vector<pair<int, int> > > adj;
vector<int> dist;
vector<bool> visit;
int main()
{
	int n, m;	//n : number of node, m : number of edge
	cin >> n >> m;
	adj.resize(n + 1);
	dist.assign(n + 1, INF);
	visit.resize(n + 1);
	while (m--)
	{
		int a, b, c;	//a : start of edge, b : end of edge, c : cost
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	int s, e;	//s : start, e : end;
	cin >> s >> e;
	priority_queue<pair<int, int> > pq;
	pq.push({ 0, s });
	
	visit[s] = 1;
	dist[s] = 0;
	while (pq.size())
	{
		int cur = pq.top().second;
		pq.pop();

		if (visit[cur]) continue;
		visit[cur] = 1;

		for (auto i : adj[cur])
		{
			int v = i.first, c = i.second;
			if (dist[v] > dist[cur] + c)
			{
				dist[v] = dist[cur] + c;
				pq.push({ -dist[v], v });
			}
		}
	}

	if (dist[e] == INF) cout << -1;
	else cout << dist[e];
}