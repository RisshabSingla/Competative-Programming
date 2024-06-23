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

bool isPossible(vector<ll> &arr, ll n, ll t, ll mid)
{
    ll count = 0;
    for (auto i : arr)
    {
        count += (mid / i);
        if (count >= t)
        {
            return true;
        }
    }
    // cout << "Mid is: " << mid << " count is: " << count << "\n";
    return count >= t;
}

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr.begin(), arr.end());
    ll high = LONG_MAX;
    ll low = 1;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isPossible(arr, n, t, mid))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}