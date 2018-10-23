#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

/*
    segment tree algorithm
    created by Choi Chang Gyu.
                                */

int tree[4 * MAX];
int n, m, k, s;

void update(int p, int x)
{
    p += s - 1;
    int old_value = tree[p];
    while (p)
    {
        tree[p] += x - old_value;
        p >>= 1;
    }
}

int query(int l, int r, int p, int x, int y)
{
    if (l > y || r < x) return 0;
    if (l <= x && r >= y) return tree[p];
    int mid = (x + y) >> 1;
    return query(l, r, p << 1, x, mid) + query(l, r, (p << 1) + 1, mid + 1, y);
}

int main()
{
    cin >> n >> m >> k;          // n : number of element, m, k : number of query
    s = 1 << int(ceil(log2(n))); // start point

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x; // value of i'th element
        update(i, x);
    }

    m += k;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c); // query (change value of b to c)
        else
            cout << query(b, c, 1, 1, s) << "\n"; // query (return sum of from b to c)
    }
}