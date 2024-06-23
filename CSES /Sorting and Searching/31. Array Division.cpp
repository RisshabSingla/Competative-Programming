#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> &arr, ll k, ll sum, ll n)
{
    ll curr = 0;
    ll count = 1;
    for (ll i = 0; i < n; i++)
    {
        if (sum < arr[i])
        {
            return false;
        }
        curr += arr[i];
        if (curr > sum)
        {
            count++;
            curr = arr[i];
        }
    }
    // cout << "Sum: " << sum << " Count is: " << count << "\n";
    return count <= k;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll low = 0;
    ll high = LLONG_MAX;
    ll ans = 0;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid, n))
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans;

    return 0;
}