#include <iostream>
#include <vector>
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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr;
        for (ll i = 0; i < n; i++)
        {
            ll t;
            cin >> t;
            if (i + 1 > t)
            {
                arr.push_back({t, i + 1});
            }
        }
        sort(arr.begin(), arr.end());
        ll ans = 0;
        n = arr.size();
        for (ll i = 0; i < n; i++)
        {
            ll index = arr[i].second;
            pair<ll, ll> p(index + 1, -1);
            auto itr = upper_bound(arr.begin(), arr.end(), p);
            if (itr == arr.end())
            {
                continue;
            }
            // cout << itr->first << " " << itr->second << "\n";
            // cout << "Adding: " << (n - (itr - arr.begin())) << "\n";
            ans += (n - (itr - arr.begin()));
        }
        cout << ans << "\n";
    }
    return 0;
}