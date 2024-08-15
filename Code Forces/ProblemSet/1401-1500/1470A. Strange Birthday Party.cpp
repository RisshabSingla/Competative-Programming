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
        ll n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        vector<ll> cost(m);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i]--;
        }
        for (ll i = 0; i < m; i++)
        {
            cin >> cost[i];
        }
        sort(arr.begin(), arr.end(), greater<ll>());
        ll index = 0;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            if (index < m && cost[index] < cost[arr[i]])
            {
                // cout << "Adding: " << cost[index] << "\n";
                ans += cost[index];
                index++;
            }
            else
            {
                // cout << "AddingCost: " << cost[arr[i].first] << "\n";
                ans += cost[arr[i]];
            }
        }
        cout << ans << "\n";
        // for (auto i : arr)
        // {
        //     cout << i.first << " ";
        // }
        // cout << "\n";
    }
    return 0;
}