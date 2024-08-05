#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// ll solve(vector<ll> &arr, ll start, ll end, ll req, ll sum)
// {
//     if (req == sum)
//     {
//         return 0;
//     }
//     if (start > end)
//     {
//         return INT_MAX;
//     }
//     ll a = solve(arr, start + 1, end, req, sum - arr[start]);
//     ll b = solve(arr, start, end - 1, req, sum - arr[end]);
//     if (a != INT_MAX && b != INT_MAX)
//     {
//         return min(a, b) + 1;
//     }
//     a = min(a + 1, ll(INT_MAX));
//     b = min(b + 1, ll(INT_MAX));
//     return min(a, b);
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, req;
        cin >> n >> req;
        vector<ll> arr(n);

        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (sum == req)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<ll> pref(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }

        if (pref[n] < req)
        {
            cout << -1 << "\n";
            continue;
        }
        ll ans = LLONG_MAX;
        for (ll i = 1; i <= n; i++)
        {
            ll curr = pref[i - 1] + req;
            if (pref[n] < curr)
            {
                continue;
            }
            auto itr = upper_bound(pref.begin(), pref.end(), curr);
            itr--;
            ll dist = itr - pref.begin();
            ans = min(ans, n - dist + i - 1);
        }

        cout << ans << "\n";

        // ll ans = solve(arr, 0, n - 1, req, sum);
        // if (ans == INT_MAX)
        // {
        //     ans = -1;
        // }
        // cout << ans << "\n";
    }
    return 0;
}