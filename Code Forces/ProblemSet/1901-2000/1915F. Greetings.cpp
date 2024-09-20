#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
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
        vector<pll> arr(n);
        vector<ll> endTimes(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            endTimes[i] = arr[i].second;
        }
        sort(arr.begin(), arr.end());
        sort(endTimes.begin(), endTimes.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll complete = arr[i].second;
            auto itr = lower_bound(endTimes.begin(), endTimes.end(), complete);
            ll index = itr - endTimes.begin();
            ans += index;
            endTimes.erase(itr);
        }
        cout << ans << "\n";
    }
    return 0;
}