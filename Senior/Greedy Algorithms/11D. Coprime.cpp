#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
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
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]] = i;
        }
        ll ans = -1;
        for (ll i = 1; i <= 1000; i++)
        {
            if (!mp.count(i))
            {
                continue;
            }
            for (ll j = 1; j <= 1000; j++)
            {
                if (!mp.count(j))
                {
                    continue;
                }
                if (gcd(i, j) == 1)
                {
                    ans = max(ans, mp[i] + mp[j] + 2);
                }
            }
        }
        cout << ans << "\n";

        // ll ans = -1;
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     for (ll j = i; j >= 0 && i + j + 2 > ans; j--)
        //     {
        //         if (gcd(arr[i], arr[j]) == 1)
        //         {
        //             ans = max(i + j + 2, ans);
        //         }
        //     }
        // }
        // cout << ans << "\n";
    }
    return 0;
}