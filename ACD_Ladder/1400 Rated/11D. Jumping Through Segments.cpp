#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<vector<ll>> &arr, ll n, ll k)
{
    ll mini = -k;
    ll maxi = k;
    for (ll i = 0; i < n; i++)
    {
        mini = max(mini, arr[i][0]);
        maxi = min(maxi, arr[i][1]);
        if (mini > maxi)
        {
            return false;
        }
        mini -= k;
        maxi += k;
    }
    if (mini > maxi)
    {
        return false;
    }
    return true;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            arr[i] = {a, b};
        }

        ll left = 0;
        ll right = LLONG_MAX;
        ll ans = 0;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (isPossible(arr, n, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}