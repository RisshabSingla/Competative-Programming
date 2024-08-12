#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// ll sumOfNElems(ll n)
// {
//     return ((n) * (n + 1)) / 2;
// }

// bool isPossible(ll level, ll x, ll k)
// {
//     ll sum = 0;
//     level--;
//     if (level >= k)
//     {
//         sum = sumOfNElems(k) + sumOfNElems(k - 1) + sumOfNElems(2 * k - level - 1);
//     }
//     else
//     {
//         sum = sumOfNElems(level);
//     }
//     // cout << "Sum for level: " << level << " sum: " << sum << "\n";
//     if (sum > x)
//     {
//         return false;
//     }
//     return true;
// }

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll k, x;
        cin >> k >> x;
        ll left = 1;
        ll right = 2 * k - 1;
        ll ans = 0;
        ll total = k * k;
        ll req = 0;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (mid > k)
            {
                ll diff = mid - k;
                ll val = k - diff;
                req = total - (val * (val + 1)) / 2;
            }
            else
            {
                req = (mid * (mid - 1)) / 2;
            }
            if (x > req)
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}