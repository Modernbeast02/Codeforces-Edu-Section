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
    vector<ll> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    SegmentTree SGT(2 * n);
    vector<ll> ans(n, 0);
    for (int iteration = 0; iteration < 2; iteration++)
    {
        map<ll, ll> index;
        for (int i = 0; i < 2 * n; i++)
        {
            ll num = v[i];
            if (index.find(num) == index.end())
            {
                index[num] = i;
                SGT.update(0, 0, 2 * n - 1, i, 1);
            }
            else
            {
                SGT.update(0, 0, 2 * n - 1, index[num], 0);
                ans[num - 1] += SGT.query(0, 0, 2 * n - 1, index[num], i);
            }
        }

        reverse(v.begin(), v.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
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