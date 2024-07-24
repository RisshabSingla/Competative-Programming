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
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            // ll t;
            // cin >> t;
            cin >> arr[i];
            // mp[t]++;
        }
        sort(arr.begin(), arr.end());
        // ll count = 0;
        // for (auto &i : mp)
        // {
        //     if (mp.count(i.first + 1))
        //     {
        //         ll c = i.first * i.second + mp[i.first + 1] * (i.first + 1);
        //         cout << "org c is: " << c << "\n";
        //         if (c > m)
        //         {
        //             ll diff1 = c - m;
        //             ll red1 = diff1 / i.first;
        //             if (diff1 % (i.first))
        //             {
        //                 red1++;
        //             }
        //             ll red2 = diff1 / (i.first + 1);
        //             if (diff1 % (i.first + 1))
        //             {
        //                 red2++;
        //             }

        //             for (ll j = 0; j <= red1; j++)
        //             {
        //                 ll c1 = c - j * i.first;
        //                 ll diffx = c1 - m;
        //                 ll redx = diffx / (i.first + 1);
        //                 if (diff1 % (i.first + 1))
        //                 {
        //                     redx++;
        //                 }
        //                 if (redx > mp[i.first + 1])
        //                 {
        //                     continue;
        //                 }
        //                 ll c2 = c - j * i.first - redx * (i.first + 1);
        //                 if (c2 > m)
        //                 {
        //                     continue;
        //                 }
        //                 c = c2;
        //             }

        //             // ll c2 = c - red2 * (i.first + 1);

        //             // c = max(c1, c2);
        //             // cout << "c1 is: " << c1 << " c2: " << c2 << "\n";
        //             // cout << "red1: " << red1 << " red2: " << red2 << "\n";
        //         }
        //         // c = min(c, m);

        //         count = max(count, c);
        //     }
        //     ll c = i.first * i.second;
        //     if (c > m)
        //     {
        //         ll red = (c - m) / i.first;
        //         ll c1 = c - red * i.first;
        //         cout << "c is: " << c << "\n";
        //         c = c1;
        //     }
        //     count = max(count, c);
        // }

        // cout << count << "\n";

        ll start = 0;
        ll count = 0;
        ll maxi = 0;
        ll current = 0;
        for (ll i = 0; i < n; i++)
        {
            current += arr[i];
            while (start <= i && ((arr[i] - arr[start]) > 1 || current > m))
            {
                current -= arr[start];
                start++;
            }
            if (current <= m)
            {
                maxi = max(current, maxi);
            }
        }
        cout << maxi << "\n";
    }
    return 0;
}
