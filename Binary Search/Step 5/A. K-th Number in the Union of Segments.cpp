#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll findNums(ll mid, vector<pair<ll, ll>> &v, ll k)
{
    ll n = v.size();
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second >= mid)
        {
            ans += max(0LL, mid - v[i].first + 1);
        }
        else
        {
            ans += v[i].second - v[i].first + 1;
        }
    }
    return ans >= k;
}
ll findNextNumber(ll ans, vector<pair<ll, ll>> &v)
{
    ll num = 1e18;
    for (int i = 0; i < v.size(); i++)
    {
        if (ans <= v[i].second && ans >= v[i].first)
        {
            return ans;
        }
        else if (v[i].first >= ans)
        {
            num = min(num, v[i].first);
        }
    }
    return num;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    k++;
    vector<pair<ll, ll>> v(n);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
        sum += b - a + 1;
    }
    ll ans = 0;
    ll low = -2e9, high = 2e9;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (findNums(mid, v, k))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    ans = findNextNumber(ans, v);
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