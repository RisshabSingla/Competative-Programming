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

// ll recursive(ll n, ll sum1, ll sum2)
// {
//     if (n == 0)
//     {
//         if (sum1 == sum2)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     ll a = recursive(n - 1, sum1 + n, sum2);
//     ll b = recursive(n - 1, sum1, sum2 + n);
//     return (a + b) % mod;
// }

// ll recursive2(ll n, ll sum1, ll num)
// {
//     if (n == 0)
//     {
//         ll sum2 = (((num) * (num + 1)) / 2) - sum1;
//         if (sum1 == sum2)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     ll a = recursive2(n - 1, sum1 + n, num);
//     ll b = recursive2(n - 1, sum1, num);
//     return (a + b) % mod;
// }

// ll dp[501][int(1e5)];

// ll memo(ll n, ll sum1, ll num)
// {
//     if (n == 0)
//     {
//         ll sum2 = (((num) * (num + 1)) / 2) - sum1;
//         if (sum1 == sum2)
//         {
//             return 1;
//         }
//         return 0;
//     }

//     if (dp[n][sum1] != -1)
//     {
//         return dp[n][sum1];
//     }
//     ll a = memo(n - 1, sum1 + n, num);
//     ll b = memo(n - 1, sum1, num);
//     return dp[n][sum1] = (a + b) % mod;
// }

// int modInverse(ll num)
// {
//     for (int x = 1; x < mod; x++)
//         if (((num % mod) * (x % mod)) % mod == 1)
//             return x;
//     return 0;
// }

int main()
{
    ll n;
    cin >> n;

    // cout << (recursive2(n, 0, n)) / 2;

    // ll sum = (((n) * (n + 1)) / 2);
    // if (sum % 2)
    // {
    //     cout << 0 << "\n";
    //     return 0;
    // }
    // memset(dp, -1, sizeof(dp));

    // ll inverse2 = 500000004;
    // // cout << modInverse(2) << "\n";
    // cout << (memo(n, 0, n) * inverse2) % mod;

    ll sum = (((n) * (n + 1)) / 2);
    if (sum % 2)
    {
        cout << 0 << "\n";
        return 0;
    }

    ll req = sum / 2;
    vector<ll> dp(sum + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = req; j >= i; j--)
        {
            (dp[j] += dp[j - i]) %= mod;
        }
    }
    ll inverse2 = 500000004;
    cout << (dp[req] * inverse2) % mod;

    return 0;
}