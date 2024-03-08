#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class DSU
{
public:
    vector<int> parent, size, mini, maxi;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            mini.push_back(i);
            maxi.push_back(i);
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
            maxi[pv] = max(maxi[pv], maxi[pu]);
            mini[pv] = min(mini[pv], mini[pu]);
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxi[pu] = max(maxi[pu], maxi[pv]);
            mini[pu] = min(mini[pu], mini[pv]);
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
        cin >> s;
        if (s == "union")
        {
            ll a, b;
            cin >> a >> b;
            dsu.unionSize(a, b);
        }
        else
        {
            ll a;
            cin >> a;
            ll par = dsu.findPar(a);
            cout << dsu.mini[par] << " " << dsu.maxi[par] << " " << dsu.size[par] << endl;
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