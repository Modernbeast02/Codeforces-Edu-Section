#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define endl '\n'

bool check(ld time, vector<ld> &x, vector<ld> &v)
{
    int n = x.size();
    ld mini = -1e18;
    ld maxi = 1e18;
    for (int i = 0; i < n; i++)
    {
        mini = max(mini, x[i] - time * v[i]);
        maxi = min(maxi, x[i] + time * v[i]);
    }
    if (maxi >= mini)
    {
        return true;
    }
    return false;
}
void solve()
{
    ld n;
    cin >> n;
    vector<ld> x(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> v[i];
    }
    ld low = 0, high = 1e9;
    int cnt = 0;
    ld ans = 1e9;
    while (low <= high && cnt < 200)
    {
        ld mid = (low + high) / (2.0);
        if (check(mid, x, v))
        {
            ans = mid;
            high = mid;
        }
        else
        {
            low = mid;
        }
        cnt++;
    }
    cout << fixed << setprecision(12) << ans << endl;
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