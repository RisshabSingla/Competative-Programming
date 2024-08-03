#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// int dp[100002][1001];

// ll recursive(vector<pair<ll, ll>> &arr, ll total, ll index, ll n)
// {
//     if (total < 0)
//     {
//         return -1;
//     }
//     if (index == n)
//     {
//         return 0;
//     }

//     if (dp[total][index] != -1)
//     {
//         return dp[total][index];
//     }
//     ll a = recursive(arr, total - arr[index].first, index + 1, n);
//     if (a != -1)
//     {
//         a += arr[index].second;
//     }
//     ll b = recursive(arr, total, index + 1, n);
//     // cout << "a is: " << a << " b is: " << b << "\n";
//     return dp[total][index] = max(a, b);
// }

int main()
{
    ll n, total;
    cin >> n >> total;
    vector<pair<int, int>> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].second;
    }

    // memset(dp, -1, sizeof(dp));
    // cout << recursive(arr, total, 0, n);

    // ll dp[n + 1][total + 1];

    // memset(dp, 0, sizeof(dp));

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int k = 1; k <= total; k++)
    //     {
    //         dp[i][k] = dp[i - 1][k];
    //         if (k >= arr[i - 1].first)
    //         {
    //             dp[i][k] = max(dp[i][k], dp[i - 1][k - arr[i - 1].first] + arr[i - 1].second);
    //         }
    //     }
    // }

    // cout << dp[n][total];

    vector<int> prev(total + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        vector<int> next(total + 1, 0);
        for (int k = 1; k <= total; k++)
        {
            next[k] = prev[k];
            if (k >= arr[i - 1].first)
            {
                next[k] = max(next[k], prev[k - arr[i - 1].first] + arr[i - 1].second);
            }
        }
        prev = next;
    }
    cout << prev[total];

    return 0;
}