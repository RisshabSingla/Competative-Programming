#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpl;
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

        vector<ll> suffixSums(n + 1, 0);
        for (ll i = n - 1; i >= 0; i--)
        {
            suffixSums[i] = suffixSums[i + 1] + arr[i];
        }
        ll ans = suffixSums[0];
        for (ll i = 1; i < n; i++)
        {
            if (suffixSums[i] > 0)
            {
                ans += suffixSums[i];
            }
        }
        cout << ans << "\n";

        // ll suffixSum = 0;
        // ll index = 0;
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     suffixSum += arr[i];
        //     if (suffixSum >= 0)
        //     {
        //         index = i;
        //         break;
        //     }
        // }
        // ll ans = 0;
        // ll mul = 1;
        // for (ll i = 0; i < index; i++, mul++)
        // {
        //     ans += (arr[i] * mul);
        // }
        // ans += (suffixSum * mul);
        // cout << ans << "\n";
    }
    return 0;
}