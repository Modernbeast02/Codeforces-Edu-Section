#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

public:
    void unionSize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

public:
    void unionRank(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++)
    {
        string s;
        ll u, v;
        cin >> s >> u >> v;
        if (s == "union")
        {
            dsu.unionSize(u, v);
        }
        else
        {
            ll par = dsu.findPar(u);
            ll par2 = dsu.findPar(v);
            if (par == par2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}