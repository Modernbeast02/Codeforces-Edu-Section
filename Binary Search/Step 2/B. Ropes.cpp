#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool check(double mid, vector<double> &v, ll k)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += (int)(v[i] / mid);
    }
    return ans >= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long double low = 0, high = (long double)1e9;
    long double ans = 0;
    ll cnt = 0;
    while (low <= high && cnt < 100)
    {
        double mid = (low + high) / 2.0;
        if (check(mid, v, k))
        {
            ans = mid;
            low = mid;
        }
        else
        {
            high = mid;
        }
        cnt++;
    }
    cout << fixed << setprecision(8) << ans << endl;
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