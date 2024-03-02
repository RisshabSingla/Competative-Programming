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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        vector<ll> a;
        a.push_back(arr[0]);
        a.push_back(arr[1]);
        a.push_back(arr[n - 2]);
        a.push_back(arr[n - 1]);

        for (ll i = 0; i < 4; i++)
        {
            for (ll j = 0; j < 4; j++)
            {
                if (j == i)
                {
                    continue;
                }
                for (ll k = 0; k < 4; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    for (ll l = 0; l < 4; l++)
                    {
                        if (l == j || l == i || l == k)
                        {
                            continue;
                        }
                        ll ab = abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[k] - a[l]) + abs(a[l] - a[i]);
                        ans = max(ans, ab);
                    }
                }
            }
        }

        // for (ll i = 0; i < n; i++)
        // {
        //     for (ll j = 0; j < n; j++)
        //     {
        //         if (j == i)
        //         {
        //             continue;
        //         }
        //         for (ll k = 0; k < n; k++)
        //         {
        //             if (k == i || k == j)
        //             {
        //                 continue;
        //             }
        //             for (ll l = 0; l < n; l++)
        //             {

        //                 if (l == j || l == i || l == k)
        //                 {
        //                     continue;
        //                 }
        //                 ll a = abs(arr[i] - arr[j]) + abs(arr[j] - arr[k]) + abs(arr[k] - arr[l]) + abs(arr[l] - arr[i]);
        //                 ans = max(ans, a);
        //             }
        //         }
        //     }
        // }
        cout << ans << "\n";
    }
    return 0;
}
