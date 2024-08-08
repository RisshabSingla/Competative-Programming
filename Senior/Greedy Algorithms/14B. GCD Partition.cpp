#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }
        ll ans = 0;
        for (ll i = 1; i < n; i++)
        {
            ll a = gcd(pref[i], pref[n] - pref[i]);
            // cout << pref[i] << ' ' << pref[n] - pref[i] << "\n";
            ans = max(ans, a);
        }
        cout << ans << "\n";
    }
    return 0;
}