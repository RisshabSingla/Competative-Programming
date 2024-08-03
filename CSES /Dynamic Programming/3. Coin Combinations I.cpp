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
    ll n, sum;
    cin >> n >> sum;
    vector<ll> coins(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    vector<ll> arr(sum + 1, 0);
    arr[0] = 1;
    for (ll i = 1; i <= sum; i++)
    {
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
            (arr[i] += (arr[i - j])) %= mod;
        }
    }

    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    cout << arr[sum];

    return 0;
}