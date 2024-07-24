#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

ll solve(vector<ll> &arr, ll n)
{
    unordered_map<ll, ll> mp;
    for (auto i : arr)
    {
        mp[i]++;
    }

    for (ll i = n - 1; i >= 0; i--)
    {
        while (i > 0 && arr[i] == arr[i - 1])
        {
            mp[arr[i]]--;
            i--;
        }
        mp[arr[i]]--;
        if (mp[arr[i]] == 0)
        {
            mp.erase(arr[i]);
        }
        if (mp.count(arr[i]))
        {
            return mp.size();
        }
        if (i > 0 && arr[i - 1] > arr[i])
        {
            return mp.size();
        }
    }
    return 0;
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

        cout << solve(arr, n) << "\n";

        // unordered_map<ll, ll> mp;
        // bool isDecreasing = false;
        // ll prevNum = LLONG_MIN;
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     if (arr[i] < prevNum)
        //     {
        //         isDecreasing = true;
        //     }
        //     prevNum = arr[i];
        //     mp[arr[i]]++;
        // }
        // if (!isDecreasing)
        // {
        //     cout << 0 << "\n";
        //     continue;
        // }

        // if (mp[arr[n - 1]] > 1)
        // {
        //     cout << mp.size() << "\n";
        //     continue;
        // }
        // ll prev = LLONG_MAX;
        // unordered_map<ll, ll> changed;
        // ll count = 0;
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     // cout << "Arr is: " << arr[i] << " prev is: " << prev << "\n";
        //     if (arr[i] > prev && !changed.count(arr[i]))
        //     {
        //         // cout << "Inside\n";
        //         changed[arr[i]]++;
        //         prev = 0;
        //         count++;
        //     }
        //     else if (changed.count(arr[i]))
        //     {
        //         prev = 0;
        //     }
        //     else
        //     {
        //         prev = arr[i];
        //     }
        // }
        // cout << count << "\n";

        // vector<bool> changed(n, false);
        // unordered_map<ll, ll> mp;
        // ll prev = arr[0];
        // ll count = 0;
        // for (ll i = 1; i < n; i++)
        // {
        //     if (mp.count(arr[i]))
        //     {
        //         changed[i] = true;
        //         prev = 0;
        //     }
        //     else if (arr[i] < prev)
        //     {
        //         mp[prev]++;
        //         prev = arr[i];
        //         count++;
        //         changed[i - 1] = true;
        //     }
        //     else
        //     {
        //         prev = arr[i];
        //     }
        // }

        // ll index = n - 1;
        // for (ll i = n - 1; i >= 0; i--)
        // {
        //     if (changed[i])
        //     {
        //         index = i;
        //         break;
        //     }
        // }
        // for (ll i = index; i >= 0; i--)
        // {
        //     if (!changed[i] && !mp.count(arr[i]))
        //     {
        //         mp[arr[i]]++;
        //         count++;
        //     }
        //     }
        // cout << count << "\n";
    }
    return 0;
}