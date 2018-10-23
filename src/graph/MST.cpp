#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

/*
        MST algorithm
    created by Choi Chang Gyu.
                                */

struct edge
{
    int a, b, c; // to, from, cost
};
bool operator<(const edge &a, const edge &b)
{
    return a.c > b.c;
}

int parent[MAX];

int Find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = Find(parent[x]);
}

bool Union(edge &x)
{
    int a = Find(x.a);
    int b = Find(x.b);

    if (a == b)
        return false;

    if (parent[a] > parent[b])
        swap(a, b);

    parent[b] = parent[a];
    return true;
}

int main()
{
    int minimum_cost = 0, remain, n, m; // n : number of vertex, m : number of edge
    cin >> n >> m;

    priority_queue<edge> pq;
    while (m--)
    {
        int a, b, c; //to, from, cost
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    for (int i = 1; i <= n; i++) // init parent
        parent[i] = i;

    remain = n - 1; // number of remain edge until make tree
    while (remain)
    {
        edge cur = pq.top();
        pq.pop();
        if (!Union(cur))
            continue;
        minimum_cost += cur.c;
        remain--;
    }

    cout << minimum_cost;
}