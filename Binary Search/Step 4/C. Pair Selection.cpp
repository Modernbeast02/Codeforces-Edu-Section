#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl '\n'

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ld> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    ll cnt = 0;
    ld ans = 0;
    ld low = 0, high = 1e18;
    while (low <= high && cnt < 100)
    {
        ld mid = (low + high) / 2.0;
        vector<ld> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back(a[i] - mid * b[i]);
        }
        sort(v.rbegin(), v.rend());
        ld sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += v[i];
        }
        if (sum >= 0)
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