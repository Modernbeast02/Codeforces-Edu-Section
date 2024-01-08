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
    void build(ll ind, ll low, ll high)
    {
        if (low == high)
        {
            segment[ind] = 1;
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);
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

    ll query(ll ind, ll sum, ll low, ll high)
    {
        if (low == high)
        {
            return low;
        }
        ll leftInd = 2 * ind + 1;
        ll rightInd = 2 * ind + 2;
        ll mid = low + (high - low) / 2;
        if (segment[rightInd] > sum)
        {
            return query(rightInd, sum, mid + 1, high);
        }
        else
        {
            return query(leftInd, sum - segment[rightInd], low, mid);
        }
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
    }
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1);
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = SGT.query(0, v[i], 0, n - 1);
        SGT.update(0, 0, n - 1, ans[i], 0);
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] + 1 << " ";
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