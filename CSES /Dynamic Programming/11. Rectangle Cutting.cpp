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

// int recursive(int a, int b)
// {
//     if (a == b)
//     {
//         return 0;
//     }
//     int ans = 10000;
//     for (int i = 1; i < a; i++)
//     {
//         ans = min(ans, recursive(a - i, b) + recursive(i, b) + 1);
//     }
//     for (int i = 1; i < b; i++)
//     {
//         ans = min(ans, recursive(a, b - i) + recursive(a, i) + 1);
//     }
//     return ans;
// }

// int dp[501][501];

// int memo(int a, int b)
// {
//     if (a == b)
//     {
//         return 0;
//     }
//     if (dp[a][b] != -1)
//     {
//         return dp[a][b];
//     }
//     int ans = 10000;
//     for (int i = 1; i < a; i++)
//     {
//         ans = min(ans, memo(a - i, b) + memo(i, b) + 1);
//     }
//     for (int i = 1; i < b; i++)
//     {
//         ans = min(ans, memo(a, b - i) + memo(a, i) + 1);
//     }
//     return dp[a][b] = ans;
// }

int main()
{
    ll a, b;
    cin >> a >> b;

    // cout << recursive(a, b);

    // memset(dp, -1, sizeof(dp));
    // cout << memo(a, b);

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 10000));

    for (int i = 0; i <= min(a, b); i++)
    {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    cout << dp[a][b];

    return 0;
}