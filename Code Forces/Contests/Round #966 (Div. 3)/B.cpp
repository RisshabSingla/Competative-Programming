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
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<ll, ll> mp;
        mp[arr[0]]++;
        bool possible = true;
        for (ll i = 1; i < n; i++)
        {
            if (mp.count(arr[i] - 1))
            {
                mp[arr[i]]++;
                continue;
            }
            if (mp.count(arr[i] + 1))
            {
                mp[arr[i]]++;
                continue;
            }
            possible = false;
            break;
        }
        if (possible)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
