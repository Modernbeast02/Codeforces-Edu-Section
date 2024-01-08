#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

struct node
{
    ll mini;
    ll cnt = 0;
};

class SegmentTree
{
    vector<node> segment;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n + 1);
    }
    void build(ll ind, ll low, ll high, vector<ll> &v)
    {
        if (low == high)
        {
            node res;
            res.mini = v[low];
            res.cnt = 1;
            segment[ind] = res;
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        if (segment[2 * ind + 1].mini < segment[2 * ind + 2].mini)
        {
            segment[ind] = segment[2 * ind + 1];
        }
        else if (segment[2 * ind + 1].mini > segment[2 * ind + 2].mini)
        {
            segment[ind] = segment[2 * ind + 2];
        }
        else
        {
            segment[ind].mini = segment[2 * ind + 1].mini;
            segment[ind].cnt = segment[2 * ind + 1].cnt + segment[2 * ind + 2].cnt;
        }
    }

    void update(ll ind, ll low, ll high, ll index, ll val)
    {
        if (low == high)
        {
            node res;
            res.mini = val;
            res.cnt = 1;
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
        if (segment[2 * ind + 1].mini < segment[2 * ind + 2].mini)
        {
            segment[ind] = segment[2 * ind + 1];
        }
        else if (segment[2 * ind + 1].mini > segment[2 * ind + 2].mini)
        {
            segment[ind] = segment[2 * ind + 2];
        }
        else
        {
            segment[ind].mini = segment[2 * ind + 1].mini;
            segment[ind].cnt = segment[2 * ind + 1].cnt + segment[2 * ind + 2].cnt;
        }
    }

    node query(ll ind, ll low, ll high, ll left, ll right)
    {
        if (high < left || low > right)
        {
            node res;
            res.mini = 1e18;
            res.cnt = 1;
            return res;
        }
        if (low >= left && high <= right)
        {
            return segment[ind];
        }
        ll mid = low + (high - low) / 2;
        node leftQuery = query(2 * ind + 1, low, mid, left, right);
        node rightQuery = query(2 * ind + 2, mid + 1, high, left, right);
        node ans;
        if (leftQuery.mini < rightQuery.mini)
        {
            ans = leftQuery;
        }
        else if (leftQuery.mini > rightQuery.mini)
        {
            ans = rightQuery;
        }
        else
        {
            ans.mini = leftQuery.mini;
            ans.cnt = leftQuery.cnt + rightQuery.cnt;
        }
        return ans;
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
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (x == 1)
        {
            ll a, b;
            cin >> a >> b;
            SGT.update(0, 0, n - 1, a, b);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            cout << SGT.query(0, 0, n - 1, a, b - 1).mini << " " << SGT.query(0, 0, n - 1, a, b - 1).cnt << endl;
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