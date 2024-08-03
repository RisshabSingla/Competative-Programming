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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // vector<ll> dp(n, 1);
    // ll maxi = 1;
    // for (ll i = 1; i < n; i++)
    // {
    //     for (ll j = i - 1; j >= 0; j--)
    //     {
    //         if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
    //         {
    //             dp[i] = dp[j] + 1;
    //             maxi = max(maxi, dp[i]);
    //         }
    //     }
    // }
    // cout << maxi;

    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        auto itr = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (itr == ans.end())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int index = itr - ans.begin();
            ans[index] = arr[i];
        }
    }
    cout << ans.size();
    return 0;
}