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
    ll maxi = 2e5 + 1;
    vector<ll> dp(maxi, 0);
    dp[1] = 1;
    for (ll i = 2; i < maxi; i++)
    {
        dp[i] = dp[i - 1] + (log2(i) / log2(3) + 1);
    }
    while (cases--)
    {
        ll left, right;
        cin >> left >> right;
        ll first = (log2(left) / log2(3) + 1);
        cout << 2 * first + dp[right] - dp[left] << "\n";
        // ll first = log2(left) / log2(3) + 1;
        // ll total = 0;
        // for (ll i = left; i <= right; i++)
        // {
        //     total += (log2(i) / log2(3) + 1);
        // }
        // total += first;
        // cout << total << "\n";
    }
    return 0;
}
