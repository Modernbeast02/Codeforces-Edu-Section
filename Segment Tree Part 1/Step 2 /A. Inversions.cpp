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
    vector<ll> v(n + 1, 0);
    ll ans = 0;
    SegmentTree SGT(n);
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cout << SGT.query(0, 0, n - 1, x, n) << " ";
        SGT.update(0, 0, n - 1, x - 1, 1);
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