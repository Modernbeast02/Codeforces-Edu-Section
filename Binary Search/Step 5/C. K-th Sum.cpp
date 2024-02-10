#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    ll low = 0, high = 1e10;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            ll index = lower_bound(b.begin(), b.end(), mid - a[i]) - b.begin() - 1;
            if (index >= 0 && index < n)
            {
                cnt += index + 1;
            }
        }
        if (cnt <= k - 1)
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