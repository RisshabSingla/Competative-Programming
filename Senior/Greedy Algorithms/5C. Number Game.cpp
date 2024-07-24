#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

bool isPossible(vector<ll> &arr, ll k, ll n)
{
    if (k == 0)
    {
        return true;
    }
    ll end = n - 1;
    ll start = 0;
    ll val = k;
    while (end >= 0 && arr[end] > k)
    {
        end--;
    }
    // cout << "k is: " << k << "\n";
    // cout << "End is: " << end << "\n";
    if (end < 0)
    {
        return false;
    }
    // if (k == 1)
    // {
    //     return true;
    // }
    for (ll i = 1; i < k; i++)
    {
        ll val = k - i + 1;
        while (end >= start && arr[end] > val)
        {
            end--;
        }
        end--;
        start++;
        // cout << "end is: " << end << " start is: " << start << "\n";
        if (start > end)
        {
            return false;
        }
    }
    val = 1;
    while (end >= start && arr[end] > val)
    {
        end--;
    }
    // end--;
    if (start > end)
    {
        return false;
    }
    // if (start <= end)
    // {
    //     return true;
    // }

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
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll start = 0;
        ll end = n;
        ll ans = 0;
        while (start <= end)
        {
            ll mid = start + (end - start) / 2;
            if (isPossible(arr, mid, n))
            {
                start = mid + 1;
                ans = mid;
            }
            else
            {
                end = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}