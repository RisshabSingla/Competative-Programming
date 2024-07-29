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
        vector<ll> arr(n - 1);
        for (ll i = 0; i < n - 1; i++)
        {
            cin >> arr[i];
        }
        vector<ll> ans(n);
        ans[0] = arr[0];
        for (ll i = 1; i < n - 1; i++)
        {
            ans[i] = arr[i] | arr[i - 1];
        }
        ans[n - 1] = arr[n - 2];

        bool possible = true;
        for (int i = 0; i < n - 1; i++)
        {
            ll a = ans[i] & ans[i + 1];
            if (a != arr[i])
            {
                possible = false;
                break;
            }
        }
        if (!possible)
        {
            cout << -1 << "\n";
            continue;
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
