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

bool isPossible(vector<ll> &pref, ll k, ll n, ll givenTime)
{
    for (ll i = k; i <= n; i++)
    {
        ll time = pref[i] - pref[i - k];
        if (time <= givenTime)
        {
            return true;
        }
    }
    return false;
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
    vector<ll> pref(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + arr[i - 1];
    }
    ll left = 0;
    ll right = n;
    ll ans = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (isPossible(pref, mid, n, t))
        {
            left = mid + 1;
            ans = mid;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}