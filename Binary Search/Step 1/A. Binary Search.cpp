#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(ll x, vector<ll> &v)
{
    ll n = v.size();
    ll low = 0;
    ll high = n - 1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (v[mid] == x)
        {
            return true;
        }
        if (v[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
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
    for (int i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        if (check(x, v))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
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