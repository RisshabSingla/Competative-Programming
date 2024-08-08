#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<ll> next(n, n);
        for (ll i = n - 2; i >= 0; i--)
        {
            if (arr[i] == arr[i + 1])
            {
                next[i] = next[i + 1];
            }
            else
            {
                next[i] = i + 1;
            }
        }
        // vector<unordered_map<ll, ll>> dp(n + 1);
        // dp[0] = {};
        // for (ll i = 1; i <= n; i++)
        // {
        //     dp[i] = dp[i - 1];
        //     dp[i][arr[i - 1]]++;
        // }
        // for (auto i : dp)
        // {
        //     for (auto j : i)
        //     {
        //         cout << j.first << " " << j.second << "\n";
        //     }
        //     cout << "\n";
        // }

        ll q;
        cin >> q;
        while (q--)
        {
            ll left, right;
            cin >> left >> right;
            left--;
            right--;
            if (next[left] > right)
            {
                cout << "-1 -1\n";
            }
            else
            {
                cout << left + 1 << " " << next[left] + 1 << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}