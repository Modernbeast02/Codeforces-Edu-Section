#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

bool isPossible(string &curr, string &y)
{
    ll i = 0, j = 0;
    while (i < curr.size() && j < y.size())
    {
        if (curr[i] == y[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    return j == y.size();
}

bool check(ll mid, string &s, string &y, vector<ll> &v)
{
    ll n = s.size();
    ll m = y.size();
    string curr = "";
    ll j = 0;
    vector<ll> f;
    for (int i = 0; i < mid; i++)
    {
        f.push_back(v[i]);
    }
    sort(f.begin(), f.end());
    for (int i = 0; i < n; i++)
    {
        if (j < mid && f[j] == i)
        {
            j++;
        }
        else
        {
            curr += s[i];
        }
    }
    return isPossible(curr, y);
}
void solve()
{
    string s, y;
    cin >> s >> y;
    ll n = s.size();
    ll m = y.size();
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i]--;
    }
    ll high = n;
    ll low = 0;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (check(mid, s, y, v))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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