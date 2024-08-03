#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int dp[101][1000001];

// ll findAns(vector<ll> &coins, ll sum, ll index, ll n)
// {
//     if (sum == 0)
//     {
//         return 1;
//     }
//     if (sum < 0)
//     {
//         return 0;
//     }
//     if (index == n)
//     {
//         return 0;
//     }
//     if (dp[index][sum] != -1)
//     {
//         return dp[index][sum];
//     }
//     ll a = findAns(coins, sum - coins[index], index, n);
//     ll b = findAns(coins, sum, index + 1, n);
//     return dp[index][sum] = (a + b) % mod;
// }

int main()
{
    int n, sum;
    // memset(dp, -1, sizeof(dp));
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // cout << findAns(coins, sum, 0, n);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // int dp[n + 1][sum + 1];
    // memset(dp, 0, sizeof(dp));
    // for (ll i = 0; i < n; i++)
    // {
    //     dp[i][0] = 1;
    // }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int k = 1; k <= sum; k++)
    //     {
    //         int skip = dp[i + 1][k];
    //         int pick = 0;
    //         if (coins[i] <= k)
    //         {
    //             pick = dp[i][k - coins[i]];
    //         }
    //         dp[i][k] = (skip + pick) % mod;
    //     }
    // }

    // for (ll i = 0; i <= n; i++)
    // {
    //     for (ll j = 0; j <= sum; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << dp[0][sum];

    vector<int> prev(sum + 1, 0);
    prev[0] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(sum + 1, 0);
        curr[0] = 1;
        for (int k = 1; k <= sum; k++)
        {
            int skip = prev[k];
            int pick = 0;
            if (coins[i] <= k)
            {
                pick = curr[k - coins[i]];
            }
            curr[k] = (skip + pick) % mod;
        }
        // for (auto j : curr)
        // {
        //     cout << j << " ";
        // }
        // cout << '\n';
        prev = curr;
    }
    cout << prev[sum];
    return 0;
}