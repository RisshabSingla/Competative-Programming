#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int mod = 1000000007;

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maxiOdd = 0;
        ll maxiEven = 0;
        // ll even = 0;
        // ll odd = 0;
        vector<ll> odds;
        vector<ll> evens;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2)
            {
                odds.push_back(arr[i]);
                maxiOdd = max(maxiOdd, arr[i]);
                // odd++;
            }
            else
            {
                evens.push_back(arr[i]);
                maxiEven = max(maxiEven, arr[i]);
                // even++;
            }
        }

        if (evens.size() == 0 || odds.size() == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        ll count = 0;
        ll index = 0;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0 && arr[i] < maxiOdd)
            {
                count++;
                arr[i] += maxiOdd;
                maxiOdd = max(maxiOdd, arr[i]);
                index = i;
            }
        }
        bool done = true;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 != arr[0] % 2)
            {
                done = false;
            }
        }
        if (done)
        {
            cout << count << "\n";
            continue;
        }

        arr[index] = maxiOdd + maxiEven;
        count++;

        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                count++;
            }
        }
        cout << count << "\n";

        // ll index1 = 0;
        // ll maxiOdd = odds.back();
        // ll count = 0;
        // while (index1 < evens.size())
        // {
        //     // cout << "odd: " << maxiOdd << " even: " << evens[index1] << "\n";
        //     if (evens[index1] <= maxiOdd)
        //     {
        //         // cout << "Less\n";
        //         count++;
        //         maxiOdd = max(maxiOdd, evens[index1] + maxiOdd);
        //         index1++;
        //     }
        //     else
        //     {
        //         // cout << "More\n";
        //         count++;
        //         maxiOdd += evens[index1];
        //     }
        // }
        // cout << count << "\n";
        // if (even == 0 || odd == 0)
        // {
        //     cout << "0\n";
        //     continue;
        // }
        // cout << max(odd, even) << "\n";
        // if (maxiOdd >= maxiEven)
        // {
        //     cout << even << "\n";
        //     continue;
        // }

        // ll count = 0;
        // while (maxiOdd < maxiEven)
        // {
        //     maxiOdd += maxiEven;
        //     count++;
        // }
        // count += even;
        // cout << count << "\n";
    }
    return 0;
}
