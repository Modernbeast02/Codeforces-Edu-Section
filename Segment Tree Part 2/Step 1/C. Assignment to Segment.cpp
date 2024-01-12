#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

struct node
{
    ll num, time;
};

class SegmentTree
{
    vector<node> segment;

public:
    SegmentTree(ll n)
    {
        segment.resize(4 * n);
    }

    node merge(node left, node right)
    {
        if (left.time > right.time)
        {
            return left;
        }
        return right;
    }

    void update(ll ind, ll low, ll high, ll left, ll right, ll val, ll time)
    {
        if (left > high || right < low)
        {
            return;
        }
        if (low >= left && high <= right)
        {
            segment[ind].num = val;
            segment[ind].time = time;
            return;
        }
        ll mid = low + (high - low) / 2;
        update(2 * ind + 1, low, mid, left, right, val, time);
        update(2 * ind + 2, mid + 1, high, left, right, val, time);
    }
    node query(ll ind, ll low, ll high, ll index)
    {
        if (low > index || high < index)
        {
            node ans;
            ans.time = ans.num = 0;
            return ans;
        }
        if (low == high)
        {
            return segment[ind];
        }
        ll mid = low + (high - low) / 2;
        node leftQuery = query(2 * ind + 1, low, mid, index);
        node rightQuery = query(2 * ind + 2, mid + 1, high, index);

        node ans = merge(leftQuery, rightQuery);
        ans = merge(ans, segment[ind]);
        return ans;
    }
};
void solve()
{
    ll n, m;
    cin >> n >> m;
    SegmentTree SGT(n);
    for (int i = 0; i < m; i++)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            r--;
            SGT.update(0, 0, n - 1, l, r, v, i + 1); // always start time with positive number
        }
        else
        {
            ll index;
            cin >> index;
            cout << SGT.query(0, 0, n - 1, index).num << endl;
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