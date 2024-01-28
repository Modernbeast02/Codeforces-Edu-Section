#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll findMaxBalloons(ll time, pair<ll, pair<ll, ll>> &v)
{
    ll t = v.first;
    ll z = v.second.first;
    ll y = v.second.second;
    ll timeTakenForZ = z * t + y;
    ll balloons = (time / timeTakenForZ) * z;
    ll timeLeft = time % timeTakenForZ;
    balloons += min(timeLeft / t, z);
    return balloons;
}
bool check(ll mid, vector<pair<ll, pair<ll, ll>>> &v, ll m)
{
    ll ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ll balloons = findMaxBalloons(mid, v[i]);
        ans += balloons;
    }
    return ans >= m;
}
void solve()
{
    ll m, n;
    cin >> m >> n;
    vector<pair<ll, pair<ll, ll>>> v(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, {b, c}};
    }
    ll low = 0, high = 1e9;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, v, m))
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
    ll left = m;
    for (int i = 0; i < n; i++)
    {
        ll balloon = findMaxBalloons(ans, v[i]);
        if (left >= balloon)
        {
            left -= balloon;
            cout << balloon << " ";
        }
        else
        {
            cout << left << " ";
            left = 0;
        }
    }
    cout << endl;
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