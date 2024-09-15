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
        if (arr[0] > arr[1])
        {
            swap(arr[0], arr[1]);
        }
        while (q--)
        {
            ll pos;
            cin >> pos;
            if (pos < arr[0] && pos < arr[1])
            {
                ll minDist = min(arr[0] - 1, arr[1] - 1);
                ll corner = pos - 1;
                cout << max(corner, minDist) << "\n";
                continue;
            }
            if (pos > arr[0] && pos > arr[1])
            {
                ll minDist = min(n - arr[0], n - arr[1]);
                ll corner = n - pos;
                cout << max(corner, minDist) << "\n";
                continue;
            }
            ll mid = (arr[0] + arr[1]) / 2;
            ll dist = abs(pos - mid);
            ll minDist = min(mid - arr[0], arr[1] - mid);
            cout << minDist << '\n';
        }
    }
    return 0;
}
