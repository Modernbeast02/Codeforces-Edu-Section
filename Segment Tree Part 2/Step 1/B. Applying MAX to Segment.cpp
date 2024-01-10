#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class SegmentTree
{
    vector<ll> segment, lazy;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    void build(ll index, ll low, ll high)
    {
        if (low == high)
        {
            segment[index] = 0;
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid);
        build(2 * index + 2, mid + 1, high);
        segment[index] = max(segment[2 * index + 1], segment[2 * index + 2]);
    }

    ll query(ll index, ll low, ll high, ll l, ll r)
    {
        if (lazy[index] != 0)
        {
            segment[index] = max(segment[index], lazy[index]);
            if (low != high)
            {
                lazy[2 * index + 1] = max(lazy[index], lazy[2 * index + 1]);
                lazy[2 * index + 2] = max(lazy[index], lazy[2 * index + 2]);
            }
            lazy[index] = 0;
        }
        if (low > r || high < l)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return segment[index];
        }
        ll mid = low + (high - low) / 2;
        ll queryLeft = query(2 * index + 1, low, mid, l, r);
        ll queryRight = query(2 * index + 2, mid + 1, high, l, r);
        return max({segment[index], queryLeft, queryRight});
    }

    void update(ll index, ll low, ll high, ll l, ll r, ll value)
    {
        if (lazy[index] != 0)
        {
            segment[index] = max(segment[index], lazy[index]);
            if (low != high)
            {
                lazy[2 * index + 1] = max(lazy[index], lazy[2 * index + 1]);
                lazy[2 * index + 2] = max(lazy[index], lazy[2 * index + 2]);
            }
            lazy[index] = 0;
        }
        if (low > r || high < l)
        {
            return;
        }
        if (low >= l && high <= r)
        {
            segment[index] = max(segment[index], value);
            if (low != high)
            {
                lazy[2 * index + 1] = max(segment[index], lazy[2 * index + 1]);
                lazy[2 * index + 2] = max(segment[index], lazy[2 * index + 2]);
            }
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * index + 1, low, mid, l, r, value);
        update(2 * index + 2, mid + 1, high, l, r, value);
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
            ll a, b, u;
            cin >> a >> b >> u;
            SGT.update(0, 0, n - 1, a, b - 1, u);
        }
        else
        {
            ll k;
            cin >> k;
            ll ans = SGT.query(0, 0, n - 1, k, k);
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