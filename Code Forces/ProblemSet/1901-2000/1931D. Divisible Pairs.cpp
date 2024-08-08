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

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // unordered_map<ll, ll> mp1;
        // unordered_map<ll, ll> mp2;
        ll count = 0;
        map<pair<ll, ll>, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll req1 = arr[i] % x;
            ll req2 = arr[i] % y;
            count += mp[{(x - req1) % x, req2}];
            mp[{req1, req2}]++;
        }
        cout << count << "\n";

        // ll n, x, y;
        // cin >> n >> x >> y;
        // vector<ll> arr(n);
        // unordered_map<ll, vector<ll>> mp1;
        // for (ll i = 0; i < n; i++)
        // {
        //     cin >> arr[i];
        //     mp1[arr[i] % x].push_back(i);
        // }
        // ll count = 0;
        // for (ll i = 0; i < n; i++)
        // {
        //     ll req = (x - arr[i] % x) % x;
        //     if (!mp1.count(req))
        //     {
        //         continue;
        //     }
        //     auto itr = upper_bound(mp1[req].begin(), mp1[req].end(), i);
        //     if (itr == mp1[req].end())
        //     {
        //         continue;
        //     }
        //     while (itr != mp1[req].end())
        //     {
        //         ll number = arr[*itr];
        //         if ((arr[i] - number) % y == 0)
        //         {
        //             count++;
        //         }
        //         // cout << *itr << " ";
        //         itr++;
        //     }
        //     // cout << "\n";
        // }
        // cout << count << "\n";
    }
    return 0;
}