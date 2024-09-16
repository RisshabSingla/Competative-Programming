#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

    ll n;
    cin >> n;
    vector<ll> arr(n);
    map<ll, ll> mp;
    ll maxi = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i] - i - 1] += arr[i];
    }
    for (auto &i : mp)
    {
        maxi = max(maxi, i.second);
    }
    cout << maxi << "\n";

    // ll n;
    // cin >> n;
    // vector<ll> arr(n);
    // vector<ll> dp(n, 0);
    // ll ans = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    //     dp[i] = arr[i];
    //     ans = max(ans, arr[i]);
    // }
    // for (ll i = 1; i < n; i++)
    // {
    //     for (ll j = i - 1; j >= 0; j--)
    //     {
    //         if (i - j == arr[i] - arr[j])
    //         {
    //             dp[i] = max(dp[i], dp[i] + arr[j]);
    //             ans = max(ans, dp[i]);
    //         }
    //     }
    // }
    // cout << ans << "\n";
    return 0;
}