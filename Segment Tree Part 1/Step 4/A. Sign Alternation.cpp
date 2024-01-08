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
        segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
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
        segment[ind] = segment[2 * ind + 1] + segment[2 * ind + 2];
    }

    ll query(ll ind, ll low, ll high, ll left, ll right)
    {
        if (high < left || low > right)
        {
            return 0;
        }
        if (low >= left && high <= right)
        {
            return segment[ind];
        }
        ll mid = low + (high - low) / 2;
        ll leftQuery = query(2 * ind + 1, low, mid, left, right);
        ll rightQuery = query(2 * ind + 2, mid + 1, high, left, right);
        return leftQuery + rightQuery;
    }
};

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (i % 2)
        {
            v[i] *= -1;
        }
    }
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1, v);
    ll q;
    cin >> q;
    while (q--)
    {
        ll type, a, b;
        cin >> type >> a >> b;
        if (type == 0)
        {
            a--;
            if (a % 2)
            {
                b *= -1;
            }
            SGT.update(0, 0, n - 1, a, b);
        }
        else
        {
            a--, b--;
            ll sum = SGT.query(0, 0, n - 1, a, b);
            if (a % 2)
            {
                sum *= -1;
            }
            cout << sum << endl;
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