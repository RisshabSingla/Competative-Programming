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
        vector<ll> end(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
            end[i] = arr[i].second;
        }
        sort(arr.begin(), arr.end());
        sort(end.begin(), end.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll complete = arr[i].second;
            auto itr = lower_bound(end.begin(), end.end(), complete);
            ll index = itr - end.begin();
            ans += index;
            end.erase(itr);
        }
        cout << ans << "\n";
    }
    return 0;
}