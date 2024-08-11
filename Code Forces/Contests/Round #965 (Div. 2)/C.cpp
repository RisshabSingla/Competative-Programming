#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<pair<ll, bool>> &arr, ll median, ll operations, ll n)
{
    ll reqElements = (n - 1) / 2 + 2;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (arr[i].first >= median)
        {
            reqElements--;
        }
        else if (arr[i].second)
        {
            ll diff = median - arr[i].first;
            if (diff <= operations)
            {
                operations -= diff;
                reqElements--;
            }
        }
    }
    return reqElements <= 0;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, k;
        cin >> n >> k;
        vector<pair<ll, bool>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first;
        }
        bool canChange = false;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            if (t)
            {
                canChange = true;
                arr[i].second = true;
            }
            else
            {
                arr[i].second = false;
            }
        }
        sort(arr.begin(), arr.end());
        ll ans = arr.back().first;
        ll left = 0;
        ll right = 1e9;
        while (left <= right)
        {
            ll mid = left + (right - left) / 2;
            if (isPossible(arr, mid, k, n))
            {
                ans = max(ans, mid + arr.back().first);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        ll index = -1;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (arr[i].second)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << ans << "\n";
            continue;
        }
        // largest editable index
        // adding k to that
        if (index <= (n / 2 - 1))
        {
            ans = max(ans, arr[n / 2].first + arr[index].first + k);
        }
        else
        {
            ans = max(ans, arr[n / 2 - 1].first + arr[index].first + k);
        }
        cout << ans << "\n";
    }
    return 0;
}
