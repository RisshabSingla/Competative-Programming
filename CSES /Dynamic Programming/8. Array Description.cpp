#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int dp[100002][101];

// ll recursive(vector<int> &arr, ll index, ll n, ll maxi, ll prev)
// {
//     if (index == n)
//     {
//         return 1;
//     }

//     if (arr[index] != 0)
//     {
//         if (abs(arr[index] - prev) > 1)
//         {
//             return 0;
//         }
//         return dp[index][prev] = recursive(arr, index + 1, n, maxi, arr[index]);
//     }

//     ll possible[] = {prev - 1, prev, prev + 1};
//     ll ans = 0;
//     for (int i = 0; i < 3; i++)
//     {
//         if (possible[i] >= 1 && possible[i] <= maxi)
//         {
//             ans += recursive(arr, index + 1, n, maxi, possible[i]);
//             ans %= mod;
//         }
//     }
//     return dp[index][prev] = ans;
// }

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // memset(dp, -1, sizeof(dp));
    // if (arr[0] != 0)
    // {
    //     cout << recursive(arr, 1, n, m, arr[0]);
    // }
    // else
    // {
    //     ll ans = 0;
    //     for (ll i = 1; i <= m; i++)
    //     {
    //         ans += recursive(arr, 1, n, m, i);
    //     }
    //     cout << ans;
    // }

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // if (arr[0] != 0)
    // {
    //     dp[0][arr[0]] = 1;
    // }
    // else
    // {
    //     for (int i = 1; i <= m; i++)
    //     {
    //         dp[0][i] = 1;
    //     }
    // }

    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         for (int j = 1; j <= m; j++)
    //         {
    //             if (j - 1 >= 1)
    //             {
    //                 (dp[i][j] += dp[i - 1][j - 1]) %= mod;
    //             }
    //             (dp[i][j] += dp[i - 1][j]) %= mod;

    //             if (j + 1 <= m)
    //             {
    //                 (dp[i][j] += dp[i - 1][j + 1]) %= mod;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (arr[i] - 1 >= 1)
    //         {
    //             (dp[i][arr[i]] += dp[i - 1][arr[i] - 1]) %= mod;
    //         }
    //         (dp[i][arr[i]] += dp[i - 1][arr[i]]) %= mod;
    //         if (arr[i] + 1 <= m)
    //         {
    //             (dp[i][arr[i]] += dp[i - 1][arr[i] + 1]) %= mod;
    //         }
    //     }
    // }

    // ll ans = 0;
    // for (int i = 1; i <= m; i++)
    // {
    //     (ans += dp[n - 1][i]) %= mod;
    // }
    // cout << ans;

    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    vector<int> prev(m + 1, 0);

    if (arr[0] != 0)
    {
        prev[arr[0]] = 1;
    }
    else
    {
        for (int i = 1; i <= m; i++)
        {
            prev[i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> next(m + 1, 0);
        if (arr[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 1)
                {
                    (next[j] += prev[j - 1]) %= mod;
                }
                (next[j] += prev[j]) %= mod;

                if (j + 1 <= m)
                {
                    (next[j] += prev[j + 1]) %= mod;
                }
            }
        }
        else
        {
            if (arr[i] - 1 >= 1)
            {
                (next[arr[i]] += prev[arr[i] - 1]) %= mod;
            }
            (next[arr[i]] += prev[arr[i]]) %= mod;
            if (arr[i] + 1 <= m)
            {
                (next[arr[i]] += prev[arr[i] + 1]) %= mod;
            }
        }
        prev = next;
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        (ans += prev[i]) %= mod;
    }
    cout << ans;

    return 0;
}