#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

struct node
{
    ll inversions = 0;
    ll freq[42] = {0};
};

class SegmentTree
{
public:
    vector<node> segment;

    SegmentTree(ll n)
    {
        segment.resize(4 * n);
    }

    node mergeSegment(node leftSubtree, node rightSubtree)
    {
        node ans;
        ans.inversions = leftSubtree.inversions + rightSubtree.inversions;
        ll smallNumsInRightSubtree = 0;
        for (int i = 0; i < 41; i++)
        {
            ans.freq[i] += leftSubtree.freq[i] + rightSubtree.freq[i];
            ans.inversions += 1LL * (leftSubtree.freq[i] * smallNumsInRightSubtree);
            smallNumsInRightSubtree += rightSubtree.freq[i];
        }
        return ans;
    }

    void build(ll ind, ll low, ll high, vector<ll> &v)
    {
        if (low == high)
        {
            segment[ind].freq[v[low]] = 1;
            segment[ind].inversions = 0;
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        segment[ind] = mergeSegment(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    void update(ll ind, ll low, ll high, ll index, ll val, vector<ll> &v)
    {
        if (low == high)
        {
            segment[ind].freq[v[index]] = 0;
            segment[ind].freq[val] = 1;
            v[index] = val;
            return;
        }
        ll mid = low + (high - low) / 2;
        if (index <= mid)
        {
            update(2 * ind + 1, low, mid, index, val, v);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, index, val, v);
        }
        segment[ind] = mergeSegment(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    node query(ll ind, ll low, ll high, ll left, ll right)
    {
        if (low > right || high < left)
        {
            node ans;
            return ans;
        }
        if (low >= left && high <= right)
        {
            return segment[ind];
        }
        ll mid = low + (high - low) / 2;
        node leftQuery = query(2 * ind + 1, low, mid, left, right);
        node rightQuery = query(2 * ind + 2, mid + 1, high, left, right);
        return mergeSegment(leftQuery, rightQuery);
    }
};

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1, v);
    while (q--)
    {
        ll type, x, y;
        cin >> type >> x >> y;
        if (type == 1)
        {
            x--, y--;
            cout << SGT.query(0, 0, n - 1, x, y).inversions << endl;
        }
        else
        {
            x--;
            SGT.update(0, 0, n - 1, x, y, v);
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