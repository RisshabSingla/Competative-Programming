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

// int recursive(string &str1, string &str2, int index1, int index2, int n, int m)
// {
//     if (index1 == n && index2 == m)
//     {
//         return 0;
//     }
//     if (index1 == n || index2 == m)
//     {
//         return max(n - index1, m - index2);
//     }

//     if (str1[index1] == str2[index2])
//     {
//         return recursive(str1, str2, index1 + 1, index2 + 1, n, m);
//     }

//     int add = recursive(str1, str2, index1, index2 + 1, n, m);
//     int remove = recursive(str1, str2, index1 + 1, index2, n, m);
//     int replace = recursive(str1, str2, index1 + 1, index2 + 1, n, m);
//     return min({add, remove, replace}) + 1;
// }

// int dp[5001][5001];

// int memo(string &str1, string &str2, int index1, int index2, int n, int m)
// {
//     if (index1 == n && index2 == m)
//     {
//         return 0;
//     }
//     if (index1 == n || index2 == m)
//     {
//         return max(n - index1, m - index2);
//     }

//     if (dp[index1][index2] != -1)
//     {
//         return dp[index1][index2];
//     }

//     if (str1[index1] == str2[index2])
//     {
//         return dp[index1][index2] = memo(str1, str2, index1 + 1, index2 + 1, n, m);
//     }

//     int add = memo(str1, str2, index1, index2 + 1, n, m);
//     int remove = memo(str1, str2, index1 + 1, index2, n, m);
//     int replace = memo(str1, str2, index1 + 1, index2 + 1, n, m);
//     return dp[index1][index2] = min({add, remove, replace}) + 1;
// }

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    // cout << recursive(str1, str2, 0, 0, str1.length(), str2.length());

    // memset(dp, -1, sizeof(dp));
    // cout << memo(str1, str2, 0, 0, str1.length(), str2.length());

    ll n = str1.length();
    ll m = str2.length();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    cout << dp[n][m];

    return 0;
}