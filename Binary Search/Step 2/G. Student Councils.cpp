#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(ll mid, vector<ll> &v, ll k)
{
    ll n = v.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(mid, v[i]);
    }
    return ans >= k * mid;
}
void solve()
{
    ll k, n;
    cin >> k >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll sum = accumulate(v.begin(), v.end(), 0LL);
    ll low = 0, high = sum / k;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, v, k))
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