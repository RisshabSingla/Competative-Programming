#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <list>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

// void calcWays(int n, unordered_map<ll, ll> &mp)
// {
//     // ll n = 1e9;
//     // arr[0] = 0;
//     // arr[1] = 1;
//     vector<ll> arr(16, 0);
//     for (ll i = 0; i < 16; i++)
//     {
//         arr[i] = i;
//         if (i - 1 >= 0)
//         {
//             arr[i] = min(arr[i], arr[i - 1] + 1);
//         }
//         if (i - 3 >= 0)
//         {
//             arr[i] = min(arr[i], arr[i - 3] + 1);
//         }

//         if (i - 6 >= 0)
//         {
//             arr[i] = min(arr[i], arr[i - 6] + 1);
//         }

//         if (i - 10 >= 0)
//         {
//             arr[i] = min(arr[i], arr[i - 10] + 1);
//         }
//         if (i - 15 >= 0)
//         {
//             arr[i] = min(arr[i], arr[i - 15] + 1);
//         }
//         if (mp.count(i))
//         {
//             mp[i] = arr[i];
//         }
//         // lst.push_back(arr[i]);
//         // cout << arr[i] << " ";
//     }

//     for (ll i = 16; i <= n; i++)
//     {
//         ll ans = i;
//         if (i - 1 >= 0)
//         {
//             ans = min(ans, arr[15] + 1);
//         }
//         if (i - 3 >= 0)
//         {
//             ans = min(ans, arr[13] + 1);
//         }

//         if (i - 6 >= 0)
//         {
//             ans = min(ans, arr[10] + 1);
//         }

//         if (i - 10 >= 0)
//         {
//             ans = min(ans, arr[6] + 1);
//         }
//         if (i - 15 >= 0)
//         {
//             ans = min(ans, arr[1] + 1);
//         }
//         if (mp.count(i))
//         {
//             mp[i] = ans;
//         }
//         arr.push_back(ans);
//         arr.erase(arr.begin());
//     }
// }

// ll calcAns(ll n)
// {
//     if (n >= 15)
//     {
//         return n / 15 + calcAns(n % 15);
//     }

//     if (n >= 10)
//     {
//         return n / 10 + calcAns(n % 10);
//     }
//     if (n >= 6)
//     {
//         return n / 6 + calcAns(n % 6);
//     }

//     if (n >= 3)
//     {
//         return n / 3 + calcAns(n % 3);
//     }
//     return n;
// }

void calcWays(vector<int> &arr)
{
    for (ll i = 0; i < 16; i++)
    {
        arr[i] = i;
        if (i - 1 >= 0)
        {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        if (i - 3 >= 0)
        {
            arr[i] = min(arr[i], arr[i - 3] + 1);
        }

        if (i - 6 >= 0)
        {
            arr[i] = min(arr[i], arr[i - 6] + 1);
        }

        if (i - 10 >= 0)
        {
            arr[i] = min(arr[i], arr[i - 10] + 1);
        }
        if (i - 15 >= 0)
        {
            arr[i] = min(arr[i], arr[i - 15] + 1);
        }
    }
}

int main()
{
    int cases;
    cin >> cases;

    vector<int> ways(16, 0);
    calcWays(ways);

    while (cases--)
    {
        ll n;
        cin >> n;
        ll ans = n;
        if (n < 15)
        {
            cout << ways[n] << "\n";
            continue;
        }
        if (n % 15 == 8)
        {
            cout << n / 15 + 2 << "\n";
            continue;
        }

        if (n % 15 == 5)
        {
            cout << n / 15 + 1 << "\n";
            continue;
        }
        cout << n / 15 + ways[n % 15] << "\n";

        // cout << ans << "\n";
    }

    // int arr[int(1e9)];
    // vector<int> arr(1e8, 0);
    // cout << "Completed\n";

    // ll maxi = 0;

    // for (ll i = 0; i < cases; i++)
    // {
    //     ll n;
    //     cin >> n;
    //     // nums.push_back(n);
    //     // maxi = max(maxi, n);

    //     cout << calcAns(n) << "\n";
    //     // cout << arr[n] << "\n";
    // }
    // int *arr = new int[maxi + 2];

    // calcWays(arr, maxi + 2);
    // vector<ll> nums;
    // ll maxi = 0;
    // unordered_map<ll, ll> mp;
    // for (ll i = 0; i < cases; i++)
    // {
    //     // cout << nums[i] << " is: ";
    //     // cout << arr[nums[i]] << "\n";
    //     ll n;
    //     cin >> n;
    //     nums.push_back(n);
    //     mp[n] = 0;
    //     maxi = max(maxi, n);
    //     // cout << arr[n] << "\n";
    // }

    // calcWays(maxi + 2, mp);
    // for (int i = 0; i < cases; i++)
    // {
    //     cout << mp[nums[i]] << "\n";
    // }
    return 0;
}
