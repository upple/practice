#include <iostream>
#include <vector>
#include <queue>
#define INF 0x7f7f7f7f
using namespace std;

struct vc { int v, c; };
vector<vector<vc> > adj;
vector<int> dist;
vector<bool> inQ;

int main()
{
	int n, m;	//n : number of node, m : number of edge
	cin >> n >> m;
	adj.resize(n + 1);
	dist.assign(n + 1, INF);
	inQ.resize(n + 1);

	while (m--)
	{
		int a, b, c;	//a : start of edge, b : end of edge, c : cost
		cin >> a >> b >> c;
		adj[a].push_back({ b, c });
	}

	int s, e;	//s : start, e : end;
	cin >> s >> e;
	queue<int> Q;
	Q.push(s);
	dist[s] = 0;

	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		inQ[cur] = 0;

		for (auto i : adj[cur])
		{
			int v = i.v, c = i.c;
			if (dist[v] > dist[cur] + c)
			{
				dist[v] = dist[cur] + c;
				if (!inQ[v])
					inQ[v] = 1, Q.push(v);
			}
		}
	}

	if (dist[e] == INF) cout << -1;
	else cout << dist[e];
}
