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

ll getSum(ll left, ll right)
{
    return (right * (right + 1) / 2) - (left * (left - 1) / 2);
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;

        ll left = k;
        ll right = k + n - 1;
        ll ans = LLONG_MAX;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            ll sum1 = getSum(k, mid);
            ll sum2 = getSum(mid + 1, k + n - 1);
            ans = min(ans, abs(sum1 - sum2));
            if (sum1 > sum2)
            {
                // decrease the sum1
                right = mid - 1;
            }
            else
            {
                // increase the sum1
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}