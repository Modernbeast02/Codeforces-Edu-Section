#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(ll mid, ll k, vector<ll> &v)
{
    ll n = v.size();
    ll sum = 0;
    ll len = 1;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum > mid)
        {
            len++;
            sum = v[i];
        }
    }
    return len <= k;
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
    ll low = *max_element(v.begin(), v.end()), high = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, k, v))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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