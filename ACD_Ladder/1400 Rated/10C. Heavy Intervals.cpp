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

        ll n;
        cin >> n;
        // vector<ll> left(n);
        set<ll> left;
        vector<ll> right(n);
        vector<ll> weight(n);
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            left.insert(t);
            // cin >> left[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> right[i];
        }
        for (ll i = 0; i < n; i++)
        {
            cin >> weight[i];
        }
        vector<ll> diff;
        sort(right.begin(), right.end());
        for (ll i = 0; i < n; i++)
        {
            auto itr = left.upper_bound(right[i]);
            itr--;
            diff.push_back(right[i] - (*itr));
            left.erase(itr);
        }
        sort(weight.begin(), weight.end());
        sort(diff.begin(), diff.end());

        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ans += (weight[n - 1 - i] * diff[i]);
        }
        cout << ans << "\n";
        // ll n;
        // cin >> n;
        // vector<ll> left(n);
        // set<ll> right;
        // vector<ll> weight(n);
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> left[i];
        // }
        // for (ll i = 0; i < n; i++)
        // {
        //     ll t;
        //     cin >> t;
        //     right.insert(t);
        // }
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> weight[i];
        // }
        // sort(left.begin(), left.end());
        // vector<ll> diff;
        // for (ll i = 0; i < n; i++)
        // {
        //     auto itr = right.lower_bound(left[i]);
        //     diff.push_back(*itr - left[i]);
        //     right.erase(itr);
        // }
        // sort(diff.begin(), diff.end());
        // sort(weight.begin(), weight.end());
        // ll ans = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     ans += (diff[i] * weight[n - 1 - i]);
        // }
        // cout << ans << "\n";
    }
    return 0;
}