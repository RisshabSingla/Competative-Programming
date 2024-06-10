#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    // Approach 1: Using Brute Force
    // ll n, q;
    // cin >> n >> q;
    // vector<ll> arr(n, 0);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // while (q--)
    // {
    //     ll left, right, val;
    //     cin >> left >> right >> val;
    //     left--;
    //     right--;
    //     for (ll i = left; i <= right; i++)
    //     {
    //         arr[i] += val;
    //     }
    // }
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // Approach 2: Using Difference Array
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> diff(n, 0);
    while (q--)
    {
        ll left, right, val;
        cin >> left >> right >> val;
        left--;
        right--;
        diff[left] += val;
        if (right + 1 < n)
        {
            diff[right + 1] -= val;
        }
    }
    for (ll i = 1; i < n; i++)
    {
        diff[i] += diff[i - 1];
    }

    for (ll i = 0; i < n; i++)
    {
        arr[i] += diff[i];
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}