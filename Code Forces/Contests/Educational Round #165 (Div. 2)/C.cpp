#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// ll findAns(vector<ll> &arr, int k, int n)
// {
//     if (k == 0)
//     {
//         ll sum = 0;
//         for (auto i : arr)
//         {
//             sum += i;
//         }
//         return sum;
//     }

//     int min_diff = INT_MAX;
//     int index = 0;
//     vector<int> indexes;
//     for (ll j = 1; j < n - 1; j++)
//     {
//         if (arr[j - 1] - arr[j] < min_diff)
//         {
//             indexes.clear();
//             min_diff = arr[j - 1] - arr[j];
//         }
//         if (arr[j - 1] - arr[j] == min_diff)
//         {
//             indexes.push_back(j);
//         }
//         if (arr[j + 1] - arr[j] < min_diff)
//         {
//             indexes.clear();
//             min_diff = arr[j + 1] - arr[j];
//         }
//         if (arr[j + 1] - arr[j] == min_diff)
//         {
//             indexes.push_back(j);
//         }
//     }
//     ll ans = INT_MAX;
//     if (arr[1] - arr[0] < min_diff)
//     {
//         indexes.clear();
//         min_diff = arr[1] - arr[0];
//     }
//     if (arr[1] - arr[0] == min_diff)
//     {
//         ll temp = arr[0];
//         arr[0] = arr[1];
//         ans = min(ans, findAns(arr, k - 1, n));
//         arr[0] = temp;
//     }

//     if (arr[n - 2] - arr[n - 1] < min_diff)
//     {
//         indexes.clear();
//         min_diff = arr[n - 2] - arr[n - 1];
//     }

//     if (arr[n - 2] - arr[n - 1] == min_diff)
//     {
//         ll temp = arr[n - 1];
//         arr[n - 1] = arr[n - 2];
//         ans = min(ans, findAns(arr, k - 1, n));
//         arr[n - 1] = temp;
//     }

//     for (auto i : indexes)
//     {
//         if (arr[i - 1] - arr[i] == min_diff)
//         {
//             ll temp = arr[i];
//             arr[i] = arr[i - 1];
//             ans = min(ans, findAns(arr, k - 1, n));
//             arr[i] = temp;
//         }
//         else
//         {
//             ll temp = arr[i];
//             arr[i] = arr[i + 1];
//             ans = min(ans, findAns(arr, k - 1, n));
//             arr[i] = temp;
//         }
//     }
//     return ans;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << arr[1] << "\n";
            continue;
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));
        for (int i = 1; i <= k; i++)
        {
            dp[0][i] = INT_MAX;
        }

        for (ll i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                // calculating the possible sums at all indexes
                dp[i][j] = dp[i - 1][j] + arr[i];
            }
            ll mini = INT_MAX;
            for (int j = 0; j <= min(i - 1, k); j++)
            {
                mini = min(mini, arr[i - j]);
                for (int t = j; t <= k; t++)
                {
                    // current = min of curr , taking the min of prev j elements and the sum before those j elements
                    dp[i][t] = min(dp[i][t], dp[i - j - 1][t - j] + 1LL * (j + 1) * mini);
                }
            }
        }
        cout << dp[n][min(n - 1, k)] << "\n";

        // for (ll i = 0; i < k; i++)
        // {
        //     int min_diff = INT_MAX;
        //     int index = 0;
        //     for (ll j = 1; j < n - 1; j++)
        //     {
        //         if (arr[j - 1] - arr[j] < min_diff)
        //         {
        //             index = j;
        //             min_diff = arr[j - 1] - arr[j];
        //         }
        //         if (arr[j + 1] - arr[j] < min_diff)
        //         {
        //             index = j;
        //             min_diff = arr[j + 1] - arr[j];
        //         }
        //     }
        //     if (arr[1] - arr[0] < min_diff)
        //     {
        //         arr[0] = arr[1];
        //         continue;
        //     }
        //     if (arr[n - 2] - arr[n - 1] < min_diff)
        //     {
        //         arr[n - 1] = arr[n - 2];
        //         continue;
        //     }
        //     if (arr[index - 1] - arr[index] == min_diff)
        //     {
        //         arr[index] = arr[index - 1];
        //     }
        //     else
        //     {
        //         arr[index] = arr[index + 1];
        //     }
        // }

        // ll sum = 0;
        // for (auto i : arr)
        // {
        //     sum += i;
        // }
        // cout << sum << "\n";

        // cout << findAns(arr, k, n) << "\n";
    }
    return 0;
}
