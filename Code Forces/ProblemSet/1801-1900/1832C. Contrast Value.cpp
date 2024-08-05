#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// map<pair<ll, ll>, ll> mp;

// ll findLength(vector<ll> &arr, ll index, ll n, ll prev, ll contrast)
// {
//     // cout << "Index: " << index << " prev: " << prev << " contrast: " << contrast << "\n";
//     if (contrast == 0)
//     {
//         return 1;
//     }
//     if (contrast < 0)
//     {
//         return -1;
//     }
//     if (index == n)
//     {
//         return -1;
//     }

//     if (mp.count({index, contrast}))
//     {
//         return mp[{index, contrast}];
//     }
//     ll a = findLength(arr, index + 1, n, arr[index], contrast - abs(arr[index] - prev));
//     if (a == -1)
//     {
//         a = -2;
//     }
//     ll b = findLength(arr, index + 1, n, prev, contrast);
//     if (b == -1)
//     {
//         return mp[{index, contrast}] = a + 1;
//     }
//     return mp[{index, contrast}] = min(a + 1, b);
// }

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

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }
        ll curr = 0;
        ll count = 0;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i] && curr != 1)
            {
                count++;
                curr = 1;
            }
            else if (arr[i - 1] < arr[i] && curr != -1)
            {
                count++;
                curr = -1;
            }
        }

        cout << count + 1 << "\n";

        // ll contrast = 0;
        // for (ll i = 1; i < n; i++)
        // {
        //     cin >> arr[i];
        //     contrast += abs(arr[i] - arr[i - 1]);
        // }
        // if (contrast == 0)
        // {
        //     cout << 1 << "\n";
        //     continue;
        // }

        // ll maxLength = INT_MAX;
        // for (ll i = 0; i < n; i++)
        // {
        //     ll length = findLength(arr, i + 1, n, arr[i], contrast);
        //     if (length == -1)
        //     {
        //         continue;
        //     }
        //     maxLength = min(length, maxLength);
        // }
        // cout << maxLength << "\n";
    }
    return 0;
}