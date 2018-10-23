#include <bits/stdc++.h>
#define MAX 1000006
#define INF 1e9
using namespace std;

/*
        MCMF algorithm
    created by Choi Chang Gyu.
                                */

struct edge
{
    int v, f, c; // to node, flow, cost
    edge *rvs;
    edge(int _v, int _f, int _c) : v(_v), f(_f), c(_c), rvs(0) {}
};

vector<vector<edge *>> adj; // adjust list
vector<int> dist;           // distance array
edge *path[MAX];            // path
int priv[MAX];              // previous node
bool inQ[MAX];              // check node into Queue
int n, m, S, E;             // n : number of vertex, m : number of edge, S : start node, E : end node

void connect_edge(int a, int b, int f, int c) //from, to, flow, cost
{
    edge *e1, *e2;
    e1 = new edge(b, f, c);
    e2 = new edge(a, 0, -c);
    e1->rvs = e2, e2->rvs = e1;
    adj[a].push_back(e1);
    adj[b].push_back(e2);
}

bool spfa()
{
    queue<int> Q;
    dist.assign(n + 1, INF);
    Q.push(S);
    dist[S] = 0;
    while (Q.size())
    {
        int cur = Q.front();
        Q.pop();

        for (edge *e : adj[cur])
        {
            int next = e->v, c = e->c, f = e->f;
            if (f > 0 && dist[next] > dist[cur] + c)
            {
                dist[next] = dist[cur] + c;
                path[next] = e;
                priv[next] = cur;
                if (!inQ[next])
                    inQ[next] = 1, Q.push(next);
            }
        }
    }

    return dist[E] != INF;
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int a, b, f, c; // from, to node, flow, cost
        cin >> a >> b >> f >> c;
        connect_edge(a, b, f, c);
    }

    cin >> S >> E;
    int max_flow = 0, min_cost = 0;
    while (spfa())
    {
        int flow = INF;
        for (int p = E; p != S; p = priv[p])
        {
            flow = min(flow, path[p]->f);
        }

        max_flow += flow;
        for (int p = E; p != S; p = priv[p])
        {
            min_cost += path[p]->c * flow;
            path[p]->f -= flow;
            path[p]->rvs->f += flow;
        }
    }

    cout << min_cost << ' ' << max_flow;
}