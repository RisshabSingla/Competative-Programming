#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {

        ll n, m;
        cin >> n >> m;
        vector<ll> canGoTill(n + 1, 1);
        // for (ll i = 1; i <= n; i++)
        // {
        //     canGoTill[i] = i;
        // }
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            if (a > b)
            {
                swap(a, b);
            }
            // cout << "Before: " << canGoTill[b] << "\n";
            canGoTill[b] = max(canGoTill[b], a + 1);
            // cout << "After: " << canGoTill[b] << "\n";
        }
        ll node = 1;
        for (ll i = 1; i <= n; i++)
        {
            node = max(node, canGoTill[i]);
            canGoTill[i] = node;
            // if (canGoTill[i] > node)
            // {
            //     node = i;
            // }
            // canGoTill[i] = node;
        }
        // for (auto i : canGoTill)
        // {
        //     cout << i << ' ';
        // }
        // cout << "\n";
        ll count = n;
        for (ll i = 1; i <= n; i++)
        {
            count += (i - canGoTill[i]);
        }
        cout << count << "\n";

        // ll n, m;
        // cin >> n >> m;
        // set<pll> st;
        // for (ll i = 0; i < m; i++)
        // {
        //     ll a, b;
        //     cin >> a >> b;
        //     if (a > b)
        //     {
        //         swap(a, b);
        //     }
        //     st.insert({a, b});
        //     // st.insert({b, a});
        // }
        // ll count = n;
        // for (ll i = 1; i <= n; i++)
        // {
        //     ll curr = 0;
        //     for (ll j = i - 1; j >= 1; j--)
        //     {
        //         if (st.count({j, i}))
        //         {
        //             break;
        //         }
        //         curr++;
        //     }
        //     count += curr;
        // }
        // cout << count << "\n";
    }
    return 0;
}