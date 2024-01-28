#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define endl '\n'

void solve()
{
    ld c;
    cin >> c;
    ld ans = 0;
    ld low = 0, high = 1e9;
    int cnt = 0;
    while (low <= high && cnt < 200)
    {
        ld mid = (low + high) / 2.0;
        if (mid * mid + (ld)sqrt(mid) >= c)
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
    cout << fixed << setprecision(10) << ans << endl;
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