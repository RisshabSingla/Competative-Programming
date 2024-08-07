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
        ll n, t, k;
        cin >> n >> t >> k;
        vector<vector<ll>> arr(n);
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            arr[i] = {a, b};
        }
        sort(arr.begin(), arr.end());
        ll prev = 0;
        ll maxi = 0;
        for (ll i = 0; i < n; i++)
        {
            ll time = arr[i][0] - prev;
            maxi = max(time, maxi);
            prev = arr[i][1];
        }
        maxi = max(maxi, k - prev);
        if (maxi >= t)
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
