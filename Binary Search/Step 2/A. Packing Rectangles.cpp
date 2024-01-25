#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(ll mid, ll w, ll h, ll n)
{
    ll rect = mid / w;
    if (rect < 1)
    {
        return false;
    }
    ll rect2 = mid / h;
    if ((n + rect - 1) / rect <= rect2)
    {
        return true;
    }
    return false;
}
void solve()
{
    ll w, h, n;
    cin >> w >> h >> n;
    ll low = 0, high = 1e18;
    ll ans = 1e18;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, w, h, n))
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