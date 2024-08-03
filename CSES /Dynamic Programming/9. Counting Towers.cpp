#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n = 1e6 + 3;
    vector<vector<ll>> dp(n, vector<ll>(9, 0));
    for (ll i = 1; i <= 8; i++)
    {
        dp[0][i] = 1;
    }
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= 8; j++)
        {
            if (j == 1 || j == 3 || j == 4 || j == 5 || j == 6)
            {
                dp[i][j] = ((((dp[i - 1][1] + dp[i - 1][2]) % mod + dp[i - 1][4]) % mod + dp[i - 1][5]) % mod + dp[i - 1][6]) % mod;
            }
            else
            {
                dp[i][j] = ((dp[i - 1][3] + dp[i - 1][7]) % mod + dp[i - 1][8]) % mod;
            }
        }
    }

    int cases;
    cin >> cases;
    while (cases--)
    {
        int in;
        cin >> in;
        cout << (dp[in - 1][3] + dp[in - 1][7]) % mod << "\n";
    }

    return 0;
}