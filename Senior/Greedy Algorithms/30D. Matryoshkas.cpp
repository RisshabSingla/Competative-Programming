#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            mp[t]++;
        }
        vector<pair<ll, ll>> arr;
        for (auto i : mp)
        {
            arr.push_back({i.first, i.second});
        }
        // reverse(arr.begin(), arr.end());
        n = arr.size();
        ll ans = arr[0].second;
        for (ll i = 1; i < n; i++)
        {
            if (arr[i].first == arr[i - 1].first + 1)
            {
                ans += max((arr[i].second - arr[i - 1].second), 0LL);
            }
            else
            {
                ans += arr[i].second;
            }
        }
        cout << ans << "\n";

        // sort(arr.begin(), arr.end());
        // ll count = 0;
        // ll prev = -1;
        // ll prevCount = 0;
        // for (auto i : mp)
        // {
        //     if (i.first != prev + 1)
        //     {
        //         count += prevCount;
        //         prevCount = 0;
        //     }
        //     prevCount = min(prevCount, i.second);
        //     prev = i.first;
        // }
        // cout << count + prevCount << "\n";
    }
    return 0;
}