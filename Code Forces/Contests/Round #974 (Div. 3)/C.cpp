#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// bool isPossible(vector<ld> &arr, ll x, ld sum, ll n)
// {
//     arr[n - 1] += x;
//     ld nSum = (ld)sum + (ld)x;
//     ld avg = nSum / (ld)n;
//     avg /= 2.00;
//     ll index = 0;
//     while (index < n && arr[index] < avg)
//     {
//         index++;
//     }
//     arr[n - 1] -= x;
//     if (index > (n / 2))
//     {
//         return true;
//     }
//     return false;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        if (n < 3)
        {
            cout << -1 << "\n";
            continue;
        }
        sort(arr.begin(), arr.end());
        cout << max(0LL, arr[n / 2] * 2 * n - sum + 1) << '\n';

        // ll ans = -1;
        // ll start = 0;
        // ll end = LONG_MAX;
        // while (start <= end)
        // {
        //     ll mid = start + (end - start) / 2;
        //     if (isPossible(arr, mid, sum, n))
        //     {
        //         end = mid - 1;
        //         ans = mid;
        //     }
        //     else
        //     {
        //         start = mid + 1;
        //     }
        // }
        // cout << ans << "\n";
    }
    return 0;
}
