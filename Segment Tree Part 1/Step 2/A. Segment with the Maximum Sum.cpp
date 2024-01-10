#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

struct node
{
    ll sum, pref, suff, ans;
};

class SegmentTree
{
    vector<node> segment;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n + 1);
    }

    node merge(node &leftQuery, node &rightQuery)
    {
        node res;
        res.sum = leftQuery.sum + rightQuery.sum;
        res.pref = max(leftQuery.pref, leftQuery.sum + rightQuery.pref);
        res.suff = max(rightQuery.suff, rightQuery.sum + leftQuery.suff);
        res.ans = max({res.sum, leftQuery.ans, rightQuery.ans, leftQuery.suff + rightQuery.pref});
        return res;
    }
    void build(ll ind, ll low, ll high, vector<ll> &v)
    {
        if (low == high)
        {
            node res;
            res.sum = v[low];
            res.pref = max(0LL, v[low]);
            res.suff = max(0LL, v[low]);
            res.ans = max(0LL, v[low]);
            segment[ind] = res;
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        segment[ind] = merge(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    void update(ll ind, ll low, ll high, ll index, ll val)
    {
        if (low == high)
        {
            node res;
            res.sum = val;
            res.pref = max(0LL, val);
            res.suff = max(0LL, val);
            res.ans = max(0LL, val);
            segment[ind] = res;
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
        segment[ind] = merge(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    node query(ll ind, ll low, ll high, ll left, ll right)
    {
        if (high < left || low > right)
        {
            node res;
            res.sum = 0;
            res.pref = 0;
            res.suff = 0;
            res.ans = 0;
            return res;
        }
        if (low >= left && high <= right)
        {
            return segment[ind];
        }
        ll mid = low + (high - low) / 2;
        node leftQuery = query(2 * ind + 1, low, mid, left, right);
        node rightQuery = query(2 * ind + 2, mid + 1, high, left, right);
        node res = merge(leftQuery, rightQuery);
        return res;
    }
};
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1, v);
    cout << SGT.query(0, 0, n - 1, 0, n - 1).ans << endl;
    for (int i = 0; i < m; i++)
    {
        ll ind, val;
        cin >> ind >> val;
        SGT.update(0, 0, n - 1, ind, val);
        cout << SGT.query(0, 0, n - 1, 0, n - 1).ans << endl;
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