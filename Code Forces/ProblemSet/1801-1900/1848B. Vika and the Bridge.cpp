#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool isPossible(vector<ll> &arr, ll n, ll jumps)
// {
//     ll color = arr[jumps];
//     ll other = 0;
//     for (ll i = jumps; i < n; i += (jumps + 1))
//     {
//         if (arr[i] != color)
//         {
//             other++;
//         }
//     }
//     return other <= 1;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<vector<ll>> arr(k, vector<ll>(1, -1));
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            arr[t - 1].push_back(i);
        }
        for (ll i = 0; i < k; i++)
        {
            arr[i].push_back(n);
        }

        vector<vector<ll>> diff(k);
        ll ans = INT_MAX;
        for (ll i = 0; i < k; i++)
        {
            for (ll j = 1; j < arr[i].size(); j++)
            {
                diff[i].push_back(arr[i][j] - arr[i][j - 1] - 1);
            }
            if (diff[i].size() == 1)
            {
                continue;
            }
            sort(diff[i].begin(), diff[i].end(), greater<ll>());
            ll possible = max(diff[i][0] / 2, diff[i][1]);
            ans = min(ans, possible);
        }
        cout << ans << "\n";

        // ll low = 0;
        // ll high = n;
        // ll ans = 0;
        // while (low <= high)
        // {
        //     ll mid = low + (high - low) / 2;
        //     if (isPossible(arr, n, mid))
        //     {
        //         high = mid - 1;
        //         ans = mid;
        //     }
        //     else
        //     {
        //         low = mid + 1;
        //     }
        // }
        // cout << ans << "\n";
    }
    return 0;
}