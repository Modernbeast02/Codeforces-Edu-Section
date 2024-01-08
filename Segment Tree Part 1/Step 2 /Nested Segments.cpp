#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    map<ll, ll> firstOccurranceIndex, lastOccuranceIndex;
    for (int i = 0; i < 2 * n; i++)
    {
        lastOccuranceIndex[v[i]] = i;
    }
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        firstOccurranceIndex[v[i]] = i;
    }
    indexed_set<ll> lastOccurances;
    for (auto it : lastOccuranceIndex)
    {
        lastOccurances.insert(it.second);
    }
    map<ll, ll> ans;
    for (int i = 0; i < 2 * n; i++)
    {
        ll num = v[i];
        if (firstOccurranceIndex[num] == i)
        {
            ll lastIndex = lastOccuranceIndex[num];
            ans[num] = lastOccurances.order_of_key(lastIndex);
            lastOccurances.erase(lastIndex);
        }
    }
    for (auto it : ans)
    {
        cout << it.second << " ";
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