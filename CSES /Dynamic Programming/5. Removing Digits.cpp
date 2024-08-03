#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int dp[1000005];

// ll recursive(ll n)
// {
//     if (n < 10)
//     {
//         return 1;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     unordered_set<ll> digits;
//     ll temp = n;
//     while (temp)
//     {
//         digits.insert(temp % 10);
//         temp /= 10;
//     }
//     ll ans = INT_MAX;
//     for (auto i : digits)
//     {
//         if (i == 0)
//         {
//             continue;
//         }
//         ll a = recursive(n - i) + 1;
//         ans = min(a, ans);
//     }
//     return dp[n] = ans;
// }

int main()
{
    ll n;
    cin >> n;
    // memset(dp, -1, sizeof(dp));
    // cout << recursive(n) << "\n";

    vector<ll> dp(n + 1, 1e9);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        string str = to_string(i);
        for (char ch : str)
        {
            if (ch != '0')
            {
                int digit = ch - '0';
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n];

    return 0;
}