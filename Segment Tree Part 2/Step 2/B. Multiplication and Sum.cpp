#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

const ll MOD = 1e9 + 7;

class SegmentTree
{
    vector<ll> segment, multiply;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n);
        multiply.assign(4 * n, 1);
    }

    void build(ll index, ll low, ll high, vector<ll> &v)
    {
        if (low == high)
        {
            segment[index] = v[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * index + 1, low, mid, v);
        build(2 * index + 2, mid + 1, high, v);
        segment[index] = (segment[2 * index + 1] + segment[2 * index + 2]) % MOD;
    }

    ll query(ll index, ll low, ll high, ll l, ll r)
    {
        if (low > r || high < l)
        {
            return 0;
        }
        if (low >= l && high <= r)
        {
            return segment[index] % MOD;
        }
        ll mid = low + (high - low) / 2;
        ll queryLeft = query(2 * index + 1, low, mid, l, r);
        ll queryRight = query(2 * index + 2, mid + 1, high, l, r);
        return (((queryLeft + queryRight) % MOD) * multiply[index]) % MOD;
    }

    void update(ll index, ll low, ll high, ll l, ll r, ll value)
    {
        if (low > r || high < l)
        {
            return;
        }
        if (low >= l && high <= r)
        {
            multiply[index] = (multiply[index] * value) % MOD;
            segment[index] = (segment[index] * value) % MOD;
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * index + 1, low, mid, l, r, value);
        update(2 * index + 2, mid + 1, high, l, r, value);
        segment[index] = (segment[2 * index + 1] + segment[2 * index + 2]) % MOD;
        segment[index] = (segment[index] * multiply[index]) % MOD;
    }
};
void solve()
{
    ll n, q;
    cin >> n >> q;
    SegmentTree SGT(n);
    vector<ll> v(n, 1);
    SGT.build(0, 0, n - 1, v);
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