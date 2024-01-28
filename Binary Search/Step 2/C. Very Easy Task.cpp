#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll findAns(ll n, ll x, ll y)
{
    ll low = 0;
    ll high = y * n;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if ((mid / x) + (mid / y) >= n)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    if (n == 1)
    {
        cout << min(x, y) << endl;
        return;
    }
    cout << min(x, y) + findAns(n - 1, x, y) << endl;
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