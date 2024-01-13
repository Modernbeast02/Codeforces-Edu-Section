#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class SegmentTree
{
    vector<ll> segment, ORR;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n);
        ORR.resize(4 * n);
    }

    ll query(ll index, ll low, ll high, ll l, ll r)
    {
        if (low > r || high < l)
        {
            return ((1LL << 31) - 1);
        }
        if (low >= l && high <= r)
        {
            return segment[index];
        }
        ll mid = low + (high - low) / 2;
        ll queryLeft = query(2 * index + 1, low, mid, l, r);
        ll queryRight = query(2 * index + 2, mid + 1, high, l, r);
        return ((queryLeft & queryRight) | ORR[index]);
    }

    void update(ll index, ll low, ll high, ll l, ll r, ll value)
    {
        if (low > r || high < l)
        {
            return;
        }
        if (low >= l && high <= r)
        {
            ORR[index] = (ORR[index] | value);
            segment[index] = (segment[index] | value);
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * index + 1, low, mid, l, r, value);
        update(2 * index + 2, mid + 1, high, l, r, value);
        segment[index] = (segment[2 * index + 1] & segment[2 * index + 2]);
        segment[index] = (segment[index] | ORR[index]);
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    SegmentTree SGT(n);
    vector<ll> v(n, 1);
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