#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

vector<ll> finalPath;

bool check(ll mid, map<ll, vector<pair<ll, ll>>> &mpp, ll d, ll n)
{
    queue<pair<ll, ll>> q;
    q.push({1, 0});
    vector<ll> visited(n + 1, 0);
    visited[1] = 1;
    while (!q.empty())
    {
        ll len = q.size();
        for (int i = 0; i < len; i++)
        {
            ll node = q.front().first;
            ll steps = q.front().second;
            q.pop();
            if (node == n)
            {
                return true;
            }
            for (auto [nodes, weights] : mpp[node])
            {
                if (weights <= mid && !visited[nodes] && steps < d)
                {
                    q.push({nodes, steps + 1});
                    visited[nodes] = 1;
                }
            }
        }
    }
    return false;
}
void findAns(ll node, ll ans, map<ll, vector<pair<ll, ll>>> &mpp, ll d, vector<ll> &path, ll steps, ll n, vector<ll> &visited)
{
    if (node == n)
    {
        if (steps < d + 1)
        {
            path.push_back(node);
            finalPath = path;
            cout << finalPath.size() - 1 << endl;
            for (int i = 0; i < finalPath.size(); i++)
            {
                cout << finalPath[i] << " ";
            }
            cout << endl;
            exit(0);
        }
        return;
    }
    path.push_back(node);
    visited[node] = 1;
    for (auto [nodes, weights] : mpp[node])
    {
        if (weights <= ans && steps + 1 <= d && !visited[nodes])
        {
            visited[nodes] = 1;
            findAns(nodes, ans, mpp, d, path, steps + 1, n, visited);
            path.pop_back();
            visited[nodes] = 0;
        }
    }
}
void solve()
{
    ll n, m, d;
    cin >> n >> m >> d;
    map<ll, vector<pair<ll, ll>>> mpp;
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        mpp[a].push_back({b, c});
    }
    ll ans = -1;
    ll low = 0, high = 1e10;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, mpp, d, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (ans == -1)
    {
        cout << ans << endl;
        return;
    }

    vector<ll> path;
    vector<ll> visited(n + 1, 0);
    findAns(1, ans, mpp, d, path, 0, n, visited);
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
