#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll mod = 1e9 + 7;
struct matrix
{
    ll a11, a12, a21, a22;
};
class SegmentTree
{
public:
    vector<matrix> segment;

    SegmentTree(ll n)
    {
        segment.resize(4 * n + 1);
    }

    matrix merge(matrix &a, matrix &b)
    {
        matrix ans;
        ans.a11 = ((a.a11 * b.a11) % mod + (a.a12 * b.a21) % mod) % mod;
        ans.a21 = ((a.a21 * b.a11) % mod + (a.a22 * b.a21) % mod) % mod;
        ans.a12 = ((a.a11 * b.a12) % mod + (a.a12 * b.a22) % mod) % mod;
        ans.a22 = ((a.a21 * b.a12) % mod + (a.a22 * b.a22) % mod) % mod;

        return ans;
    }
    void build(ll ind, ll low, ll high, vector<matrix> &v)
    {
        if (low == high)
        {
            segment[ind] = v[low];
            return;
        }
        ll mid = low + (high - low) / 2;
        build(2 * ind + 1, low, mid, v);
        build(2 * ind + 2, mid + 1, high, v);
        segment[ind] = merge(segment[2 * ind + 1], segment[2 * ind + 2]);
    }

    matrix query(ll ind, ll low, ll high, ll left, ll right)
    {
        if (left <= low && right >= high)
        {
            return segment[ind];
        }
        if (left > high || right < low)
        {
            matrix ans;
            ans.a11 = 1;
            ans.a12 = 0;
            ans.a21 = 0;
            ans.a22 = 1;
            return ans;
        }
        ll mid = low + (high - low) / 2;
        matrix leftMat = query(2 * ind + 1, low, mid, left, right);
        matrix rightMat = query(2 * ind + 2, mid + 1, high, left, right);
        return merge(leftMat, rightMat);
    }
};

void solve()
{
    ll r, n, m;
    cin >> r >> n >> m;
    mod = r;
    vector<matrix> v(n);
    for (int i = 0; i < n; i++)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].a11 = a % mod;
        v[i].a12 = b % mod;
        v[i].a21 = c % mod;
        v[i].a22 = d % mod;
    }
    SegmentTree SGT(n);
    SGT.build(0, 0, n - 1, v);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        matrix ans = SGT.query(0, 0, n - 1, a, b);
        cout << ans.a11 << " " << ans.a12 << endl;
        cout << ans.a21 << " " << ans.a22 << endl;
        cout << endl;
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