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

int main()
{
    int cases;
    cin >> cases;
    ll num = 3e5 + 10;
    vector<ll> dp(num + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (ll i = 2; i <= num; i++)
    {
        dp[i] = ((2 * ((i - 1) * dp[i - 2]) % mod) % mod + dp[i - 1]) % mod;
    }
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        // vector<vector<int>> moves;
        ll rows = n;
        for (ll i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;
            if (a == b)
            {
                rows--;
            }
            else
            {
                rows -= 2;
            }
            // moves.push_back({a, b});
        }
        cout << dp[rows] << "\n";
    }
    return 0;
}
