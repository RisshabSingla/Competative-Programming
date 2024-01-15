#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), greater());
        vector<ll> prefix(n + 1, 0);
        for (ll i = 1; i <= n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }
        ll ans = INT_MIN;
        for (ll i = 0; i <= k; i++)
        {
            ll sum = prefix[n] + prefix[i] - 2 * prefix[min(i + x, n)];
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
    return 0;
}
