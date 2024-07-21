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
        unordered_map<ll, ll> mp;
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
            maxi = max(maxi, arr[i]);
        }
        if (mp.size() == 1)
        {
            if (n % 2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }
        bool odd = false;
        for (auto i : mp)
        {
            if (i.second % 2)
            {
                odd = true;
            }
        }
        if (!odd)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
        // if (mp[maxi] % 2 == 0)
        // {
        //     cout << "NO\n";
        // }
        // else
        // {
        //     cout << "YES\n";
        // }
    }
    return 0;
}
