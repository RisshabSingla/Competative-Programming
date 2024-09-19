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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << 1 << "\n";
        return 0;
    }
    if (k == 1)
    {
        cout << arr.back() - arr[0] + 1 << "\n";
        return 0;
    }
    vector<ll> diff;
    for (ll i = 1; i < n; i++)
    {
        diff.push_back(arr[i] - arr[i - 1]);
    }
    sort(diff.begin(), diff.end());
    ll ans = LLONG_MAX;
    ll sum = 0;
    for (ll i = 0; i <= n - k - 1; i++)
    {
        sum += diff[i];
    }
    sum++;
    // cout << "Sum is: " << sum << '\n';

    for (ll i = n - k; i < n - 1; i++)
    {
        ans = min(ans, sum + (n - 1 - i));
        sum += diff[i];
    }
    cout << ans << '\n';
    return 0;
}