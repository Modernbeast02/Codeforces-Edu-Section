#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll check(ll x, vector<ll> &v)
{
    ll n = v.size();
    ll low = 0;
    ll high = n - 1;
    ll ans = n;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (v[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans + 1;
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
    vector<ll> ans;
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        ans.push_back(check(x, v));
    }
    for (auto it : ans)
    {
        cout << it << endl;
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