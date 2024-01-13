#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class SegmentTree
{
    vector<ll> segment, mini;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n);
        mini.resize(4 * n);
    }

    ll query(ll index, ll low, ll high, ll l, ll r)
    {
        if (low > r || high < l)
        {
            return 1e18;
        }
        if (low >= l && high <= r)
        {
            return mini[index];
        }
        ll mid = low + (high - low) / 2;
        ll queryLeft = query(2 * index + 1, low, mid, l, r);
        ll queryRight = query(2 * index + 2, mid + 1, high, l, r);
        return min(queryLeft, queryRight) + segment[index];
    }

    void update(ll index, ll low, ll high, ll l, ll r, ll value)
    {
        if (low > r || high < l)
        {
            return;
        }
        if (low >= l && high <= r)
        {
            segment[index] += value;
            mini[index] += value;
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * index + 1, low, mid, l, r, value);
        update(2 * index + 2, mid + 1, high, l, r, value);
        mini[index] = min(mini[2 * index + 1], mini[2 * index + 2]) + segment[index];
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    SegmentTree SGT(n);
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll l, r, u;
            cin >> l >> r >> u;
            SGT.update(0, 0, n - 1, l, r - 1, u);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            r--;
            ll ans = SGT.query(0, 0, n - 1, l, r);
            cout << ans << endl;
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