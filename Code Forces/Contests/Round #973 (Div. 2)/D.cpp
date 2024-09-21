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

bool isPossibleMax(vector<ll> &arr, ll n, ll maxValue)
{
    ll extra = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] >= maxValue)
        {
            extra += (arr[i] - maxValue);
        }
        else
        {
            ll add = maxValue - arr[i];
            extra = max(0LL, extra - add);
        }
    }
    return extra == 0;
}

ll findMaxValue(vector<ll> &arr, ll n)
{
    ll start = 0;
    ll end = 1e12;
    ll ans = 0;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossibleMax(arr, n, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

bool isPossibleMin(vector<ll> &arr, ll n, ll minValue)
{
    ll extra = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] < minValue)
        {
            ll add = minValue - arr[i];
            extra -= add;
            if (extra < 0)
            {
                return false;
            }
        }
        else
        {
            extra += (arr[i] - minValue);
        }
    }
    return true;
}

ll findMinValue(vector<ll> &arr, ll n)
{
    ll start = 0;
    ll end = 1e12;
    ll ans = 0;
    while (start <= end)
    {
        ll mid = start + (end - start) / 2;
        if (isPossibleMin(arr, n, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

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

        ll maxValuePossible = findMaxValue(arr, n);
        ll minValuePossible = findMinValue(arr, n);
        cout << maxValuePossible - minValuePossible << "\n";
    }
    return 0;
}
