#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll k;
    cin >> k;
    vector<ll> ans;
    for (int i = 0; i < k; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll first = upper_bound(v.begin(), v.end(), r) - v.begin();
        first--;
        ll second = lower_bound(v.begin(), v.end(), l) - v.begin();
        ans.push_back(max(0LL, first - second + 1));
    }
    for (auto it : ans)
    {
        cout << it << " ";
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