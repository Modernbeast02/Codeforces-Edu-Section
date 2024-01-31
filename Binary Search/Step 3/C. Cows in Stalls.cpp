#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(ll mid, ll k, vector<ll> &v)
{
    ll n = v.size();
    ll sum = 0;
    ll len = 1;
    ll prev = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - prev >= mid)
        {
            len++;
            prev = v[i];
        }
    }
    return len >= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0;
    ll low = 0, high = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, k, v))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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