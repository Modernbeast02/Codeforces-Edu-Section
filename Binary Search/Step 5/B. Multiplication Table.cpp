#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll findLowerInColumn(ll row, ll mid, ll n)
{
    ll low = 1, high = n;
    ll ans = 0;
    while (low <= high)
    {
        ll middle = low + (high - low) / 2;
        if (row * middle <= mid)
        {
            ans = middle;
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }
    return ans;
}
ll checkNumbersLower(ll mid, ll n, ll k)
{
    ll ans = 0;
    for (int i = 1; i < min(mid + 1, n + 1); i++)
    {
        ans += findLowerInColumn(i, mid, n);
    }
    return ans >= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    ll low = 1, high = n * n;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (checkNumbersLower(mid, n, k))
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