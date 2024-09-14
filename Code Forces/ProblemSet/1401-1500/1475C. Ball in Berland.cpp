#include <iostream>
#include <vector>
#include <algorithm>

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
        ll a, b, k;
        cin >> a >> b >> k;
        vector<ll> boys(a + 1, 0);
        vector<ll> girls(b + 1, 0);
        vector<pll> pairs(k, {0, 0});
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            boys[t]++;
            pairs[i].first = t;
        }
        for (ll i = 0; i < k; i++)
        {
            ll t;
            cin >> t;
            girls[t]++;
            pairs[i].second = t;
        }
        ll ans = 0;
        for (ll i = 0; i < k; i++)
        {
            ans += (k - 1 - (boys[pairs[i].first] - 1) - (girls[pairs[i].second] - 1));
        }
        cout << ans / 2 << "\n";
    }
    return 0;
}