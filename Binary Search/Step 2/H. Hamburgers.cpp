#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    ll bread, sauce, cheese, breadPrice, saucePrice, cheesePrice;
    cin >> bread >> sauce >> cheese >> breadPrice >> saucePrice >> cheesePrice;
    ll money;
    cin >> money;
    ll breadNeeded = 0, cheeseNeeded = 0, sauceNeeded = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'B')
        {
            breadNeeded++;
        }
        else if (s[i] == 'S')
        {
            sauceNeeded++;
        }
        else
        {
            cheeseNeeded++;
        }
    }
    ll ans = 0;
    ll low = 0, high = 1e14;
    while (low <= high)
    {
        ll burgers = low + (high - low) / 2;
        ll breadNeededToMakeBurger = max(0LL, burgers * breadNeeded - bread);
        ll sauceNeededToMakeBurger = max(0LL, burgers * sauceNeeded - sauce);
        ll cheeseNeededToMakeBurger = max(0LL, burgers * cheeseNeeded - cheese);
        ll totalMoneyNeeded = breadNeededToMakeBurger * breadPrice + sauceNeededToMakeBurger * saucePrice + cheeseNeededToMakeBurger * cheesePrice;

        if (totalMoneyNeeded > money)
        {
            high = burgers - 1;
        }
        else
        {
            ans = burgers;
            low = burgers + 1;
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