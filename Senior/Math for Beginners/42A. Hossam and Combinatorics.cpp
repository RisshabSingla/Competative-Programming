#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
        ll mini = LLONG_MAX;
        ll maxi = LLONG_MIN;
        unordered_map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
            mp[arr[i]]++;
        }
        if (mp.size() == 1)
        {
            cout << (n * (n - 1)) << "\n";
            continue;
        }
        ll diff = maxi - mini;
        ll count = 0;
        // cout << "Diff is: " << diff << "\n";
        for (ll i = 0; i < n; i++)
        {
            if (mp.count((arr[i] - diff)))
            {
                count += mp[(arr[i] - diff)];
                // cout << "Found: " << arr[i] - diff << "\n";
            }

            if (mp.count((arr[i] + diff)))
            {
                count += mp[(arr[i] + diff)];
                // cout << "Found: " << arr[i] + diff << "\n";
            }
            // mp[arr[i]]++;
            // for (auto i : mp)
            // {
            //     cout << i.first << " " << i.second << "\n";
            // }
            // cout << "\n";
        }
        // for (auto i : mp)
        // {
        //     cout << i.first << " " << i.second << "\n";
        // }
        cout << count << "\n";
    }
    return 0;
}