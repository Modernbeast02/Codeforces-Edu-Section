#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class SegmentTree
{
    vector<ll> segment;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n + 1);
    }
    void build(ll ind, ll low, ll high, vector<ll> &v)
    {
        if (low == high)
        {
            segment[ind] = v[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    void update(ll ind, ll low, ll high, ll index, ll val)
    {
        if (low == high)
        {
            segment[ind] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (index <= mid)
        {
            update(2 * ind + 1, low, mid, index, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, index, val);
        }
        segment[ind] = min(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll left, ll right, ll power, ll n)
    {
        if (high < left || low > right)
        {
            return 0;
        }
        if (low == high)
        {
            if (segment[ind] <= power)
            {
                update(0, 0, n - 1, low, 1e10);
                return 1;
            }
        }
        ll mid = low + (high - low) / 2;
        if (segment[ind] <= power) // left aur right mein aur bhi values milengi
        {
            ll sum1 = 0, sum2 = 0;
            // checking left
            if (segment[2 * ind + 1] <= power)
            {
                sum1 = query(2 * ind + 1, low, mid, left, right, power, n);
            }
            // checking right
            if (segment[2 * ind + 2] <= power)
            {
                sum2 = query(2 * ind + 2, mid + 1, high, left, right, power, n);
            }
            return sum1 + sum2;
        }
        return 0;
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n, 1e10);
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1, v);
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll index, height;
            cin >> index >> height;
            SGT.update(0, 0, n - 1, index, height);
        }
        else
        {
            ll l, r, p;
            cin >> l >> r >> p;
            cout << SGT.query(0, 0, n - 1, l, r - 1, p, n) << endl;
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