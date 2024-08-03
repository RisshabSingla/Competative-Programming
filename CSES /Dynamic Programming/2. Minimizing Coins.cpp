#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    ll n, sum;
    cin >> n >> sum;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<ll> arr(sum + 1, 0);
    for (ll i = 1; i <= sum; i++)
    {
        ll mini = INT_MAX;
        for (auto j : coins)
        {
            if (j > i)
            {
                break;
            }
            if (i != j && arr[i - j] == 0)
            {
                continue;
            }
            mini = min(mini, arr[i - j] + 1);
        }
        if (mini != INT_MAX)
        {
            arr[i] = mini;
        }
    }

    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    if (arr[sum] == 0)
    {
        cout << -1;
    }
    else
    {
        cout << arr[sum];
    }
    return 0;
}