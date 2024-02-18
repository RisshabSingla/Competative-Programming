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
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        ll ans = 0;
        ll count = 0;
        for (auto i : mp)
        {
            if (i.second >= 3)
            {
                ans += (((i.second) * (i.second - 1) * (i.second - 2)) / 6);
            }
            if (i.second >= 2)
            {
                ll a = (i.second * (i.second - 1)) / 2;
                ans += (a * count);
            }
            count += i.second;
        }
        cout << ans << "\n";
        // sort(arr.begin(), arr.end());
    }
    return 0;
}
