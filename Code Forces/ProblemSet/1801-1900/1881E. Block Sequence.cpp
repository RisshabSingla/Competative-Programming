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

// ll solveRec(vector<ll> &arr, ll index, ll curr, ll n)
// {
//     if (index == n)
//     {
//         if (curr == 0)
//         {
//             return 0;
//         }
//         return 1e6;
//     }
//     ll a = LLONG_MAX;
//     ll b = LLONG_MAX;
//     ll c = LLONG_MAX;
//     if (curr == 0)
//     {
//         a = solveRec(arr, index + 1, arr[index], n);
//         // can take the curr
//     }
//     b = solveRec(arr, index + 1, max(curr - 1, 0LL), n) + 1;
//     // delete the current number
//     if (curr != 0)
//     {
//         // consider current number in sequence
//         c = solveRec(arr, index + 1, curr - 1, n);
//     }

//     // cout << "For index: " << index << " ans: " << min({a, b, c}) << "\n";
//     return min({a, b, c});
// }

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
        // cout << solveRec(arr, 0, 0, n) << "\n";

        vector<ll> dp(n + 1, 0);
        dp[n - 1] = 1;
        for (ll i = n - 2; i >= 0; i--)
        {
            ll del = 1 + dp[i + 1];
            ll take = LLONG_MAX;
            if (i + arr[i] + 1 <= n)
            {
                take = dp[i + arr[i] + 1];
            }
            dp[i] = min(del, take);
        }
        cout << dp[0] << "\n";
    }
    return 0;
}