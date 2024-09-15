#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>

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
        ll n, m, q;
        cin >> n >> m >> q;
        vector<ll> arr(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        while (q--)
        {
            ll pos;
            cin >> pos;

            if (pos < arr[0])
            {
                ll minDist = arr[0] - 1;
                ll corner = pos - 1;
                cout << max(corner, minDist) << "\n";
                continue;
            }
            if (pos > arr.back())
            {
                ll minDist = n - arr.back();
                ll corner = n - pos;
                cout << max(corner, minDist) << "\n";
                continue;
            }
            auto itr = upper_bound(arr.begin(), arr.end(), pos);
            ll right = *itr;
            ll left = *(--itr);
            ll mid = (left + right) / 2;
            ll dist = abs(pos - mid);
            ll minDist = min(mid - left, right - mid);
            cout << minDist << '\n';
        }
    }
    return 0;
}
