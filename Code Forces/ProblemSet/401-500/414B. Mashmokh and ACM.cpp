#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
typedef vector<int> vi;

const int mod = 1000000007;

vector<ll> findFactors(int n)
{
    vector<ll> factors;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                factors.push_back(i);
            else
            {
                factors.push_back(i);
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

// vector<ll> comb;

ll findPossible(ll k, ll currNum, vector<vector<ll>> &nextElems)
{
    if (k == 0)
    {
        // for (auto i : comb)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        return 1;
    }
    ll ans = 0;
    for (auto factor : nextElems[currNum])
    {
        // comb.push_back(factor);
        ans += findPossible(k - 1, factor, nextElems);
        ans %= mod;
        // comb.pop_back();
    }
    return ans;
}

ll dp[2001][2001];

ll findPossibleMemo(ll k, ll currNum, vector<vector<ll>> &nextElems)
{
    if (k == 0)
    {
        // for (auto i : comb)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";
        return 1;
    }

    if (dp[k][currNum] != -1)
    {
        return dp[k][currNum];
    }
    ll ans = 0;
    for (auto factor : nextElems[currNum])
    {
        // comb.push_back(factor);
        ans += findPossibleMemo(k - 1, factor, nextElems);
        ans %= mod;
        // comb.pop_back();
    }
    return dp[k][currNum] = ans;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> nextElems(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        vector<ll> factors = findFactors(i);
        for (auto factor : factors)
        {
            nextElems[factor].push_back(i);
        }
    }
    // for (auto i : nextElems)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans += findPossibleMemo(k - 1, i, nextElems);
        ans %= mod;
    }
    cout << ans << "\n";

    return 0;
}