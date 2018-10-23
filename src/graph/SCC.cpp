#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

/*
        SCC algorithm
    created by Choi Chang Gyu.
                                */

int v, e, a, b;
vector<int> adj[MAX];    // adjust list
vector<vector<int>> ans; // scc vector
stack<int> S;            // stack
int d[MAX], it;          // d : check cycle array, it : unique depth value
bool f[MAX];             // check finised array

int dfs(int x)
{
    d[x] = ++it;
    S.push(x);
    int p = d[x];
    for (int i : adj[x])
    {
        if (!d[i]) p = min(p, dfs(i));
        else if (!f[i]) p = min(p, d[i]);
    }

    if (p == d[x])
    {
        vector<int> scc;
        while (1)
        {
            int t = S.top();
            scc.push_back(t);
            f[t] = 1;
            S.pop();
            if (t == x)
                break;
        }

        sort(scc.begin(), scc.end());
        ans.push_back(scc);
    }

    return p;
}
int main()
{
    cin >> v >> e; // v : number of vertex, e : number of edge
    while (e--)
    {
        cin >> a >> b; // from, to node
        adj[a].push_back(b);
    }

    for (int i = 1; i <= v; i++)
        if (!d[i]) dfs(i);

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for (auto scc : ans)
    {
        sort(scc.begin(), scc.end());
        for (int i : scc)
            cout << i << " ";

        cout << "-1\n";
    }
}