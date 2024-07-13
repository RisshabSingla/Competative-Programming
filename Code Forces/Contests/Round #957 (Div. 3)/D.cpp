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

map<pair<int, int>, bool> dp;

bool isPossible(string &str, int currIndex, int n, int m, int k)
{
    if (k < 0)
    {
        return false;
    }
    if (currIndex >= n)
    {
        return true;
    }
    if (dp.count({currIndex, k}))
    {
        return dp[{currIndex, k}];
    }

    if (str[currIndex] == 'C')
    {
        return dp[{currIndex, k}] = false;
    }
    if (str[currIndex] == 'L')
    {
        for (int i = m; i >= 1; i--)
        {
            if (isPossible(str, currIndex + i, n, m, k))
            {
                return dp[{currIndex, k}] = true;
            }
        }
    }
    if (str[currIndex] == 'W')
    {
        if (isPossible(str, currIndex + 1, n, m, k - 1))
        {
            return dp[{currIndex, k}] = true;
        }
    }
    return dp[{currIndex, k}] = false;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        string str;
        cin >> str;
        str = 'L' + str + 'L';
        vector<long long> dp(n + 2, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n + 2; i++)
        {
            if (str[i] == 'C')
            {
                dp[i] = INT_MAX;
                continue;
            }
            if (str[i] == 'W')
            {
                if (i <= n)
                {
                    dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
                }
                continue;
            }
            for (int j = 1; j <= m && i + j < n + 2; j++)
            {
                if (str[i + j] == 'C')
                {
                    continue;
                }
                dp[i + j] = dp[i];
            }
        }

        cout << ((dp[n + 1] <= k) ? "YES\n" : "NO\n");

        // Recursive
        // dp.clear();
        // bool ans = false;
        // for (int i = m - 1; i >= 0; i--)
        // {
        //     if (isPossible(str, i, n, m, k))
        //     {
        //         ans = true;
        //         break;
        //     }
        // }

        // if (ans)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }

        // Not Working
        // ll currMax = m - 1;
        // ll water = k;
        // bool ans = true;
        // for (ll i = 0; i < n; i++)
        // {
        //     if (str[i] == 'C' && i >= currMax)
        //     {
        //         ans = false;
        //         break;
        //     }
        //     // cout << "i is: " << i << " str " << str[i] << " maxRange " << currMax << "\n";
        //     if (str[i] == 'L')
        //     {
        //         currMax = max(currMax, i + m);
        //     }
        //     if (i == currMax)
        //     {
        //         if (str[i] == 'W' && water > 0)
        //         {
        //             water--;
        //             continue;
        //         }
        //         ans = false;
        //         break;
        //     }
        //     // cout << "i is: " << i << " moves " << moves << "\n";
        // }
        // if (ans)
        // {
        //     cout << "YES\n";
        // }
        // else
        // {
        //     cout << "NO\n";
        // }
    }
    return 0;
}
